#include "Player.h"
#include "DxLib.h"

void Player::Update(Map& map)
{
	if (CheckHitKey(KEY_INPUT_W))
	{
		DrawString(0, 0, "W", GetColor(255, 255, 255));
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		DrawString(0, 0, "A", GetColor(255, 255, 255));
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		DrawString(0, 0, "S", GetColor(255, 255, 255));
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		DrawString(0, 0, "D", GetColor(255, 255, 255));
	}
	int nextX = x;
	int nextY = y;

	int size = 8;

	// Å©Å®
	if (CheckHitKey(KEY_INPUT_A)) nextX -= speed;
	if (CheckHitKey(KEY_INPUT_D)) nextX += speed;

	int left = (nextX - size) / 64;
	int right = (nextX + size) / 64;
	int top = (y - size) / 64;
	int bottom = (y + size) / 64;

	if (map.GetMap(left, top) == 0 &&
		map.GetMap(right, top) == 0 &&
		map.GetMap(left, bottom) == 0 &&
		map.GetMap(right, bottom) == 0)
	{
		x = nextX;
	}

	// Å™Å´
	nextY = y;

	if (CheckHitKey(KEY_INPUT_W)) nextY -= speed;
	if (CheckHitKey(KEY_INPUT_S)) nextY += speed;

	left = (x - size) / 64;
	right = (x + size) / 64;
	top = (nextY - size) / 64;
	bottom = (nextY + size) / 64;

	if (map.GetMap(left, top) == 0 &&
		map.GetMap(right, top) == 0 &&
		map.GetMap(left, bottom) == 0 &&
		map.GetMap(right, bottom) == 0)
	{
		y = nextY;
	}
}

void Player::Draw()
{
	DrawCircle(x, y, 10, GetColor(0, 0, 255), TRUE);
}

int Player::GetX() { return x; }
int Player::GetY() { return y; }