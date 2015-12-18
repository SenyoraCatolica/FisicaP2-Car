#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	fxwin = App->audio->LoadFx("Utilities/Winner2.wav");
	fxlose = App->audio->LoadFx("Utilities/Lose.wav");
	

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(1.6, 0.2, 4);
	car.chassis_offset.Set(0, 1.2, 0);
	car.cabin_size.Set(1.5, 0.8, 1);
	car.cabin_offset.Set(0, 2, -1.5);
	car.front_size.Set(0.5, 0.3, 4.2);
	car.front_offset.Set(0, 1.6, 0);
	car.bar_size.Set(2.4, 0.3, 0.2);
	car.bar_offset.Set(0, 1.5, 2);

	car.mass = 500.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 10.5;
	car.maxSuspensionForce = 9800.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.5f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 0.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 5, 35);
	

	matrix = new float[16];
	matrix[0] = 0;
	matrix[1] = 0;
	matrix[2] = 0;
	matrix[3] = 0;
	matrix[4] = 0;
	matrix[5] = 0;
	matrix[6] = 0;
	matrix[7] = 0;
	matrix[8] = 0;
	matrix[9] = 0;
	matrix[10] = 0;
	matrix[11] = 0;
	matrix[12]= 0;
	matrix[13] = 0;
	matrix[14] = 0;
	matrix[15] = 0;
	vehicle->GetTransform(matrix);

	player_time.Start();

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	delete matrix;
	return true;
}


// Update: draw background
update_status ModulePlayer::Update(float dt)
{

	//Camera
	float speed_cam = 0.85;
	
	vec3 p = vehicle->GetPos();
	vec3 f = vehicle->GetBottomVector();

	vec3 dist_to_car = { -8.0f, 5.0f, -8.0f };
	vec3 camera_new_position = { p.x + (f.x * dist_to_car.x), p.y + f.y + dist_to_car.y, p.z + (f.z * dist_to_car.z) };
	vec3 speed_camera = camera_new_position - App->camera->Position;

	App->camera->Look(App->camera->Position + (speed_cam * speed_camera), p);
	



	//--------------------------------------------------------------------
	turn = acceleration = brake = 0.0f;

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;	
	}

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		acceleration = -MAX_ACCELERATION;
	}
	
	vec3 v = vehicle->GetPos();

	if (v.y <= -50)
	{		
		App->physics->Reset(vehicle);
	}


	if (player_time.Read() / 1000 > 90)
	{
		App->scene_intro->begin_collision = true;

		if (one_sound == false)
		{
			
			App->audio->PlayFx(fxlose, 0);
			one_sound = true;
		}
		
		finLose = true;
	}


	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_REPEAT)
	{
		App->scene_intro->Restart();
	}


	

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	

	char title[80];	

	if (finWin == true)
	{
		sprintf_s(title, "You win!           Pres R to restart the game");

	}

	else if (finLose == true || lifes == 0)
	{
		sprintf_s(title, "You lose!           Pres R to try again");

	}

	else
		sprintf_s(title, "%.1f       Km/h  Do one lap in less than 90 seconds: %d", vehicle->GetKmh(), player_time.Read() / 1000);

	App->window->SetTitle(title);

	return UPDATE_CONTINUE;
}

