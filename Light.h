#pragma once
#include "Map.h"

class Light
{
public:
	void Update(Map& map, int px, int py); 
	void SetPosition(int px, int py);
	void Draw();
	bool CheckHit(int px, int py);

private:
	int x = 320;
	int y = 200;

	int searchRange = 1000;  
	int hitRange = 100;    

	int speed = 2;
};