#pragma once

class Map
{
public:

	void Draw();

private:

	const static int MAP_W = 15;
	const static int MAP_H = 11;

	int map[MAP_W][MAP_H] =
	{
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,0,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,1,0,0,1,0,1},
		{1,0,0,1,1,0,0,1,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};
};