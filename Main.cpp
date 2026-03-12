#include "DxLib.h"
#include "Map.h"
#include "Light.h"
#include "Title.h"
#include "Player.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	const int WIDTH = 960, HEIGHT = 704;

	SetGraphMode(WIDTH, HEIGHT, 32);
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	Map map;
	Light light;
	Title title;
	Player player;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();

		map.Draw();

		light.Update();
		light.Draw();

		player.Update();
		player.Draw();

		title.Draw();

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}