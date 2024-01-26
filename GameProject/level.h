#pragma once

#include "gameobject.h"
#include <vector>
#include <list>
#include <string>
#include <sgg/graphics.h>
#include "player.h"
#include "enemy.h"
#include <memory>
#include "NonCollisionObject.h"
#include "AnimatedObjects.h"
#include "saw.h"
#include "LevelDoor1.h"



class Level : public GameObject
{
public:
	graphics::Brush m_brush_background;
	graphics::Brush m_brush_health_system;


	std::vector<GameObject*> m_static_objects;
	std::list<GameObject*> m_enemy_objects;
	std::vector<std::string> m_spriteshealthsystemfull;
	std::vector<std::string> m_spriteshealthsystemalmosthalf;
	std::vector<std::string> m_spriteshealthsystemhalf;
	std::vector<std::string> m_spriteshealthsystemlastlife;
	std::vector<std::string> m_spriteshealthsystemdeath;

	// add some collidable blocks
	std::vector<CollisionObject> m_blocks;
	std::vector<std::string> m_block_names;

	//add some non collidable blocks
	std::vector<NonCollisionObject> m_non_collidable_blocks;
	std::vector<std::string> m_non_collidable_block_names;

	AnimatedObjects* m_saw1 = new saw(7.0f,9.0f);
	saw* mn_saw1 = dynamic_cast<saw*>(m_saw1);

	AnimatedObjects* m_saw2 = new saw(8.0f, 9.0f);
	saw* mn_saw2 = dynamic_cast<saw*>(m_saw2);

	AnimatedObjects* m_saw3 = new saw(9.0f, 9.0f);
	saw* mn_saw3 = dynamic_cast<saw*>(m_saw3);

	AnimatedObjects* m_saw4 = new saw(6.0f, 9.0f);
	saw* mn_saw4 = dynamic_cast<saw*>(m_saw4);

	AnimatedObjects* m_leveldoor1= new LevelDoor1(45.0f, 5.0f);
	LevelDoor1* mn_leveldoor1 = dynamic_cast<LevelDoor1*>(m_leveldoor1);

	//add some enemies
	std::vector<std::unique_ptr<Enemy>> enemies;
	const float m_block_size = 1.0f;
	graphics::Brush m_block_brush;
	graphics::Brush m_block_brush_debug;

	float m_center_x = 5.0f;
	float m_center_y = 5.0f;
	float animationtimerforhealthsystem = 0.0f;
	bool isCollidingLevelDoor1 = false;
	bool isCollidingSaw = false;


	// dedicated method to draw a block
	void drawBlock(int i);
	void drawNonCollisionBlock(int i);

	// detect collisions
	void checkCollisions();
	void checkCollisionsForEnemy();
	void checkCollisionPlayerDoor();
	void checkCollisionPlayerSaw();

	void checkCollisionsMovingObjects();


public:
	void update(float dt) override;
	void draw() override;
	void init() override;

	Level(const std::string& name = "Level0");
	~Level() override;
};