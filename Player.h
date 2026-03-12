#pragma once

class Player
{
public:

	void Update();
	void Draw();

private:

	int x = 64;
	int y = 64;

	int speed = 4;
};