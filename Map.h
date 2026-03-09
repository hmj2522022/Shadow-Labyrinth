#pragma once

class Map {
public:
	Map();
	void Draw();
	int(*GetData())[20];

private:
	int data[15][20];
};
