#include "Map.h"
#include "DxLib.h"

void Map::Draw()
{
	for (int y = 0; y < 7; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (map[y][x] == 1)
			{
				DrawBox(
					x * 64,
					y * 64,
					x * 64 + 64,
					y * 64 + 64,
					GetColor(100, 100, 100),
					TRUE
				);
			}
		}
	}
}