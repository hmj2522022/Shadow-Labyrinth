#pragma once

class Light
{
public:
	void Update();
	void Draw();

private:
	int enemyX = 320;
	int enemyY = 200;

	int direction = 0;
	int timer = 0;
};