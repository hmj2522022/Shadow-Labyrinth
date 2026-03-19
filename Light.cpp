#include "Light.h"
#include "DxLib.h"
#include <cstdlib>

void Light::SetPosition(int px, int py)
{
	x = px;
	y = py;
}

void Light::Update(Map& map, int px, int py)
{
	int dx = px - x;
	int dy = py - y;

	int dist = dx * dx + dy * dy;

	// ”ÍˆÍ“à‚¾‚¯’Ç”ö
	if (dist < searchRange * searchRange)
	{
		int mapX = x / 64;
		int mapY = y / 64;

		int playerMapX = px / 64;
		int playerMapY = py / 64;

		int bestX = mapX;
		int bestY = mapY;

		int minDist = 99999;

		int dirX[4] = { 1, -1, 0, 0 };
		int dirY[4] = { 0, 0, 1, -1 };

		for (int i = 0; i < 4; i++)
		{
			int nx = mapX + dirX[i];
			int ny = mapY + dirY[i];

			if (map.GetMap(nx, ny) == 0)
			{
				int d = abs(playerMapX - nx) + abs(playerMapY - ny);

				if (d < minDist)
				{
					minDist = d;
					bestX = nx;
					bestY = ny;
				}
			}
		}

		int targetX = bestX * 64 + 32;
		int targetY = bestY * 64 + 32;

		if (x < targetX) x += speed;
		if (x > targetX) x -= speed;
		if (y < targetY) y += speed;
		if (y > targetY) y -= speed;
	}
}

void Light::Draw()
{
	DrawCircle(x, y, hitRange, GetColor(255, 255, 0), FALSE);

	DrawCircle(x, y, 5, GetColor(255, 0, 0), TRUE);
}

bool Light::CheckHit(int px, int py)
{
	int dx = px - x;
	int dy = py - y;

	return (dx * dx + dy * dy) < (hitRange * hitRange);
}