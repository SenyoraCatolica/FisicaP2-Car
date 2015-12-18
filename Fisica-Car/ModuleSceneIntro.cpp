#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"


ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	App->audio->PlayMusic("Utilities/Song.wav");

	bool ret = true;


	finish.size = { 10, 5, 0 };
	finish.SetPos(1, 0, 30);

	sensor = App->physics->AddBody(finish, 0.0f);
	sensor->SetAsSensor(true);
	sensor->collision_listeners.add(this);



	/////////////////////////CUBEEE ROAD///////////////////////////////

	//Carretera 1
	part1.SetPos(1, 0, 103);
	part1.size = { 10, 1, 160 };
	part1.color = Green;
	App->physics->AddBody(part1, 0.0f);

	//Border
	border1.SetPos(-4, 1.5, 103);
	border1.size = { 0.5, 2, 160 };
	border1.color = White;
	App->physics->AddBody(border1, 0.0f);
	//Border
	border2.SetPos(6, 1.5, 108);
	border2.size = { 0.5, 2, 170 };
	border2.color = White;
	App->physics->AddBody(border2, 0.0f);

	//Jumps
	part2.SetPos(1, -1.5, 120);
	part2.size = { 9.5, 2, 7 };
	part2.SetRotation(-20, vec3(1, 0, 0));
	part2.color = White;
	App->physics->AddBody(part2, 0.0f);

	part3.SetPos(1, -1.5, 110);
	part3.size = { 9.5, 2, 7 };
	part3.SetRotation(-20, vec3(1, 0, 0));
	part3.color = White;
	App->physics->AddBody(part2, 0.0f);

	part4.SetPos(1, -1.5, 100);
	part4.size = { 9.5, 2, 7 };
	part4.SetRotation(-20, vec3(1, 0, 0));
	part4.color = White;
	App->physics->AddBody(part4, 0.0f);

	part5.SetPos(1, -1.5, 90);
	part5.size = { 9.5, 2, 7 };
	part5.SetRotation(-20, vec3(1, 0, 0));
	part5.color = White;
	App->physics->AddBody(part5, 0.0f);

	part6.SetPos(1, -1.5, 90);
	part6.size = { 9.5, 2, 7 };
	part6.SetRotation(-20, vec3(1, 0, 0));
	part6.color = White;
	App->physics->AddBody(part6, 0.0f);

	//First jump
	part7.SetPos(1, -0.5, 60);
	part7.size = { 5, 2, 5 };
	part7.SetRotation(-20, vec3(1, 0, 0));
	part7.color = White;
	App->physics->AddBody(part7, 0.0f);

	part8.SetPos(-32.5, 0, 188);
	part8.size = { 10, 1, 77 };
	part8.SetRotation(90, vec3(0, 1, 0));
	part8.color = Green;
	App->physics->AddBody(part8, 0.0f);

	border3.SetPos(-35.5, 1.5, 183);
	border3.size = { 1, 2, 64 };
	border3.SetRotation(90, vec3(0, 1, 0));
	border3.color = White;
	App->physics->AddBody(border3, 0.0f);

	border4.SetPos(-32.5, 1.5, 193);
	border4.size = { 1, 2, 77 };
	border4.SetRotation(90, vec3(0, 1, 0));
	border4.color = White;
	App->physics->AddBody(border4, 0.0f);

	//First diagonal
	part9.SetPos(-90, 7, 188);
	part9.size = { 40, 1, 10 };
	part9.SetRotation(-20, vec3(0, 0, 1));
	part9.color = Green;
	App->physics->AddBody(part9, 0.0f);

	part10.SetPos(-150, 13.5, 188);
	part10.size = { 83, 1, 10 };
	part10.color = Red;
	App->physics->AddBody(part10, 0.0f);

	//Rampa descendent
	part11.SetPos(-187, 6.5, 166);
	part11.size = { 10, 1, 40 };
	part11.color = Green;
	part11.SetRotation(-20, vec3(1, 0, 0));
	App->physics->AddBody(part11, 0.0f);

	part60.SetPos(-192, 7.5, 166);
	part60.size = { 1, 2, 40 };
	part60.color = White;
	part60.SetRotation(-20, vec3(1, 0, 0));
	App->physics->AddBody(part60, 0.0f);

	part62.SetPos(-182.5, 7.5, 166);
	part62.size = { 1, 2, 40 };
	part62.color = White;
	part62.SetRotation(-20, vec3(1, 0, 0));
	App->physics->AddBody(part62, 0.0f);

	part16.SetPos(-192, 17.5, 188);
	part16.size = { 2, 8, 10 };
	part16.color = Green;
	App->physics->AddBody(part16, 0.0f);

	//Ccarretera rampas
	part15.SetPos(-188, 0, 95);
	part15.size = { 20, 1, 110 };
	part15.color = Green;
	App->physics->AddBody(part15, 0.0f);

	part20.SetPos(-78, 0, 95);
	part20.size = { 20, 1, 70 };
	part20.color = Green;
	App->physics->AddBody(part20, 0.0f);

	part57.SetPos(-68, 1, 105);
	part57.size = { 1, 2, 70 };
	part57.color = White;
	App->physics->AddBody(part57, 0.0f);

	part21.SetPos(-100, 4, 115);
	part21.size = { 30, 1, 30 };
	part21.color = Green;
	part21.SetRotation(-20, vec3(0, 0, 1));
	App->physics->AddBody(part21, 0.0f);

	part50.SetPos(-100, 5, 130);
	part50.size = { 30, 2, 2 };
	part50.color = White;
	part50.SetRotation(-20, vec3(0, 0, 1));
	App->physics->AddBody(part50, 0.0f);

	part22.SetPos(-124, 9, 95);
	part22.size = { 20, 1, 70 };
	part22.color = Green;
	App->physics->AddBody(part22, 0.0f);

	part42.SetPos(-133, 0, 50);
	part42.size = { 20, 1, 90 };
	part42.color = Red;
	part42.SetRotation(90, vec3(0, 1, 0));
	App->physics->AddBody(part42, 0.0f);

	part28.SetPos(-124, 9, 50);
	part28.size = { 10, 1, 20 };
	part28.color = Green;
	App->physics->AddBody(part28, 0.0f);

	part43.SetPos(-124, 9, 20);
	part43.size = { 20, 1, 40 };
	part43.color = Green;
	App->physics->AddBody(part43, 0.0f);

	part44.SetPos(-85, 3.7, 10);
	part44.size = { 60, 1, 20 };
	part44.color = Green;
	part44.SetRotation(-10, vec3(0, 0, 1));
	App->physics->AddBody(part44, 0.0f);


	part58.SetPos(-85, 4.7, 0);
	part58.size = { 60, 3, 1 };
	part58.color = White;
	part58.SetRotation(-10, vec3(0, 0, 1));
	App->physics->AddBody(part58, 0.0f);

	part59.SetPos(-85, 4.7, 20);
	part59.size = { 60, 2, 1 };
	part59.color = White;
	part59.SetRotation(-10, vec3(0, 0, 1));
	App->physics->AddBody(part59, 0.0f);

	part45.SetPos(-30, 0, 10);
	part45.size = { 73, 1, 20 };
	part45.color = Green;
	App->physics->AddBody(part45, 0.0f);

	part46.SetPos(1, 0, 22);
	part46.size = { 10, 1, 4 };
	part46.color = Green;
	App->physics->AddBody(part46, 0.0f);

	/////////////////////////////////////////////////////
	//Rampas
	part18.SetPos(-188, 0, 140);
	part18.size = { 10, 2, 5 };
	part18.SetRotation(20, vec3(1, 0, 0));
	part18.color = White;
	App->physics->AddBody(part18, 0.0f);


	part25.SetPos(-183, -0.5, 100);
	part25.size = { 5, 2, 5 };
	part25.SetRotation(20, vec3(1, 0, 0));
	part25.color = White;
	App->physics->AddBody(part25, 0.0f);

	part26.SetPos(-183, -0.5, 80);
	part26.size = { 5, 2, 5 };
	part26.SetRotation(20, vec3(1, 0, 0));
	part26.color = White;
	App->physics->AddBody(part26, 0.0f);

	part27.SetPos(-183, -0.5, 60);
	part27.size = { 5, 2, 5 };
	part27.SetRotation(20, vec3(1, 0, 0));
	part27.color = White;
	App->physics->AddBody(part27, 0.0f);

	part23.SetPos(-193, -0.5, 60);
	part23.size = { 5, 2, 5 };
	part23.SetRotation(20, vec3(1, 0, 0));
	part23.color = White;
	App->physics->AddBody(part23, 0.0f);

	part29.SetPos(-193, -0.5, 80);
	part29.size = { 5, 2, 5 };
	part29.SetRotation(20, vec3(1, 0, 0));
	part29.color = White;
	App->physics->AddBody(part29, 0.0f);

	part30.SetPos(-188, -0.5, 90);
	part30.size = { 5, 2, 5 };
	part30.SetRotation(20, vec3(1, 0, 0));
	part30.color = White;
	App->physics->AddBody(part30, 0.0f);

	part14.SetPos(-188, -0.5, 110);
	part14.size = { 5, 2, 5 };
	part14.SetRotation(20, vec3(1, 0, 0));
	part14.color = White;
	App->physics->AddBody(part14, 0.0f);

	part13.SetPos(-188, -0.5, 70);
	part13.size = { 5, 2, 5 };
	part13.SetRotation(20, vec3(1, 0, 0));
	part13.color = White;
	App->physics->AddBody(part13, 0.0f);

	part24.SetPos(-193, -0.5, 100);
	part24.size = { 5, 2, 5 };
	part24.SetRotation(20, vec3(1, 0, 0));
	part24.color = White;
	App->physics->AddBody(part24, 0.0f);


	//Cyl

	part33.SetPos(-65, 3.5, 183);
	part33.radius = 1;
	part33.height = 7.5;
	part33.SetRotation(-90, vec3(0, 0, 1));
	part33.color = White;
	App->physics->AddBody(part33, 0.0f);


	//Cylinder
	part34.SetPos(-65, 3.5, 193);
	part34.radius = 1;
	part34.height = 7.5;
	part34.SetRotation(-90, vec3(0, 0, 1));
	part34.color = White;
	App->physics->AddBody(part34, 0.0f);

	//Cylinder
	part35.SetPos(-55, 3.5, 183);
	part35.radius = 1;
	part35.height = 7.5;
	part35.SetRotation(-90, vec3(0, 0, 1));
	part35.color = White;
	App->physics->AddBody(part35, 0.0f);


	//Cylinder
	part36.SetPos(-55, 3.5, 193);
	part36.radius = 1;
	part36.height = 7.5;
	part36.SetRotation(-90, vec3(0, 0, 1));
	part36.color = White;
	App->physics->AddBody(part36, 0.0f);

	//Cylinder
	part37.SetPos(-45, 3.5, 183);
	part37.radius = 1;
	part37.height = 7.5;
	part37.SetRotation(-90, vec3(0, 0, 1));
	part37.color = White;
	App->physics->AddBody(part37, 0.0f);


	//Cylinder
	part38.SetPos(-45, 3.5, 193);
	part38.radius = 1;
	part38.height = 7.5;
	part38.SetRotation(-90, vec3(0, 0, 1));
	part38.color = White;
	App->physics->AddBody(part38, 0.0f);

	//Cylinder
	part39.SetPos(-35, 3.5, 183);
	part39.radius = 1;
	part39.height = 7.5;
	part39.SetRotation(-90, vec3(0, 0, 1));
	part39.color = White;
	App->physics->AddBody(part39, 0.0f);


	//Cylinder
	part40.SetPos(-35, 3.5, 193);
	part40.radius = 1;
	part40.height = 7.5;
	part40.SetRotation(-90, vec3(0, 0, 1));
	part40.color = White;
	App->physics->AddBody(part40, 0.0f);

	//parte encima tunel
	part41.SetPos(-49, 7.5, 187);
	part41.size = { 15, 1, 40 };
	part41.SetRotation(90, vec3(0, 1, 0));
	part41.color = Green;
	App->physics->AddBody(part41, 0.0f);


	///////////////////////////////HINGE's/////////////////////////////////
	post.SetPos(-150, 16.5, 195);
	post.size = vec3(1, 5, 1);
	post.color = Red;
	post_body = App->physics->AddBody(post, 0.0f);

	door.SetPos(5, 3, 105);
	door.size = vec3(20, 5, 1);
	door.color = Blue;
	door_body = App->physics->AddBody(door, 1.0f);

	App->physics->AddConstraintHinge(*post_body, *door_body, vec3(-2, 0, 0), vec3(3, 0, 0), vec3(0, 1, 0), vec3(0, 1, 0), true);

	//-------------------------------------

	post1.SetPos(-80, 1, 50);
	post1.size = vec3(1, 0.5, 1);
	post1.color = Red;
	post1_body = App->physics->AddBody(post1, 0.0f);

	panel1.SetPos(7, 13, 105);
	panel1.size = vec3(20, 1, 20);
	panel1.color = Blue;
	panel1_body = App->physics->AddBody(panel1, 1.0f);

	App->physics->AddConstraintHinge(*post1_body, *panel1_body, vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 1, 0), vec3(0, 1, 0), true);
	




	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{

	part1.Render();
	part2.Render();
	border1.Render();
	border2.Render();
	border4.Render();
	border3.Render();
	part3.Render();
	part4.Render();
	part5.Render();
	part6.Render();
	part7.Render();
	part8.Render();
	part9.Render();
	part10.Render();
	part11.Render();
	part13.Render();
	part14.Render();
	part15.Render();
	part16.Render();
	part18.Render();

	part20.Render();
	part21.Render();
	part22.Render();
	part23.Render();
	part24.Render();
	part25.Render();
	part26.Render();
	part27.Render();
	part28.Render();
	part29.Render();
	part30.Render();

	part33.Render();
	part34.Render();
	part35.Render();
	part36.Render();
	part37.Render();
	part38.Render();
	part39.Render();
	part40.Render();
	part41.Render();
	part42.Render();
	part43.Render();
	part44.Render();
	part45.Render();
	part46.Render();
	part50.Render();
	part57.Render();
	part58.Render();
	part59.Render();
	part60.Render();
	part61.Render();
	part62.Render();
	


	post_body->GetTransform(&post.transform);
	post.Render();
	door_body->GetTransform(&door.transform);
	door.Render();

	post1_body->GetTransform(&post1.transform);
	post1.Render();
	panel1_body->GetTransform(&panel1.transform);
	panel1.Render();

	sensor->GetTransform(&finish.transform);
	finish.Render();




	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{

	finish.color = Blue;
	if (begin_collision == false)
	{

			begin_collision = true;
		

		if (App->player->player_time.Read() / 1000 <= 100 && App->player->player_time.GetRun() == true)
		{
			App->player->finWin = true;
			App->audio->PlayFx(App->player->fxwin, 0);
		}
	}
		
}

void ModuleSceneIntro::Restart()
{
	App->player->player_time.Start();
	begin_collision = false;
	App->player->finWin = false;
	App->player->finLose = false;
	App->player->one_sound = false;
	begin_collision = false;

	App->physics->Reset(App->player->vehicle);
}

