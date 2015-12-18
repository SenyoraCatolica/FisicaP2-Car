#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include"Timer.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	void Restart();

public:
	

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;


	////////////////////////////HINGE's/////////////////////////
	Cube finish;
	PhysBody3D* fin;
	PhysBody3D* sensor;
	
	Cube post;
	Cube door;
	PhysBody3D* post_body;
	PhysBody3D* door_body;

	Cube post1;
	Cube panel1;
	PhysBody3D* post1_body;
	PhysBody3D* panel1_body;

	Cube post2;
	Cube panel2;
	PhysBody3D* post2_body;
	PhysBody3D* panel2_body;



	////////////////////////ROAD//////////////////////////////////


	Cube part1;
	Cube border1;
	Cube border2;
	Cube border3;
	Cube border4;
	Cube part2;
	Cube part3;
	Cube part4;
	Cube part5;
	Cube part6;
	Cube part7;
	Cube part8;
	Cube part9;
	Cube part10;
	Cube part11;
	Cube part12;
	Cube part13;
	Cube part14;
	Cube part15;
	Cube part16;
	Cube part18;
	Cube part20;
	Cube part21;
	Cube part22;
	Cube part23;
	Cube part24;
	Cube part25;
	Cube part26;
	Cube part27;
	Cube part28;
	Cube part29;
	Cube part30;
	Cube part32;
	Cylinder part33;
	Cylinder part34;
	Cylinder part35;
	Cylinder part36;
	Cylinder part37;
	Cylinder part38;
	Cylinder part39;
	Cylinder part40;
	Cube part41;
	Cube part42;
	Cube part43;
	Cube part44;
	Cube part45;
	Cube part46;
	Cube part50;
	Cube part57;
	Cube part58;
	Cube part59;
	Cube part60;
	Cube part61;
	Cube part62;

	
	Timer t;
	bool begin_collision = false;
	bool win = false;
	bool lose = false;


};
