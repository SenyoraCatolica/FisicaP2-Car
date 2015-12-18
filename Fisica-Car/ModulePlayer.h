#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	void FinalLoseLifes(bool x);

public:

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;
	Timer player_time;
	uint num_volta;
	int lifes = 2;
	uint fx;
	uint fxwin;
	uint fxlose;
	bool finWin = false;
	bool finLose = false;
	bool one_sound = false;
	float* matrix;


};