#include "Map.h"
#include "DxLib.h"

void Map::Draw()
{
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			int tile = (stage == 1) ? map1[y][x] : map2[y][x];

			if (tile == 1)
			{
				DrawBox(x * 64, y * 64, x * 64 + 64, y * 64 + 64, GetColor(100, 100, 100), TRUE);
			}
		}
	}
}

int Map::GetMap(int x, int y)
{
	if (x < 0 || y < 0 || x >= W || y >= H) return 1;
	return (stage == 1) ? map1[y][x] : map2[y][x];
}

void Map::NextStage()
{
	stage++;
}

int Map::GetStage()
{
	return stage;
}

void Map::ResetStage()
{
	stage = 0;
}
