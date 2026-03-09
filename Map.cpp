#include "Map.h"
#include "DxLib.h"

Map::Map() {
	for (int y = 0; y < 15; y++)
		for (int x = 0; x < 20; x++)
			data[y][x] = 0; // 0 = ’Ê˜H
}

void Map::Draw() {
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 20; x++) {
			DrawBox(x * 32, y * 32, x * 32 + 32, y * 32 + 32, GetColor(0, 0, 0), TRUE);
		}
	}
}

int(*Map::GetData())[20] {
	return data;
	}
