#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Map.h"

class Game {
public:
	Game();
	void Update();
	void Draw();

private:
	Player player;
	Enemy enemy;
	Map map;
};
