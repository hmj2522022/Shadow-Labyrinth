#pragma once

class Enemy {
public:
	Enemy(int x, int y);
	void Update(int px, int py, int map[][20]);
	void Draw();

private:
	int x, y;
};
