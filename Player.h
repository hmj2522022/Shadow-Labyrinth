#pragma once

class Player {
public:
	Player(int x, int y);
	void Update(int map[][20]);
	void Draw();

	int GetX() const;
	int GetY() const;

private:
	int x, y;
};
