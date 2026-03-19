#pragma once
#include "Map.h"

class Player
{
public:
	void Update(Map& map);
	void Draw();

	int GetX();
	int GetY();

private:
	int x = 80;
	int y = 80;

	int speed = 4;
};