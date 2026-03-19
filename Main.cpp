#include "DxLib.h"
#include "Map.h"
#include "Light.h"
#include "Player.h"
#include "Scene.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SetGraphMode(960, 704, 32);
	SetAlwaysRunFlag(TRUE);

	if (DxLib_Init() == -1) return -1;

	int bgmHandle = LoadSoundMem("bgm.mp3");
	PlaySoundMem(bgmHandle, DX_PLAYTYPE_LOOP);
	/*int gameoverSE = LoadSoundMem("gameover.mp3");*/


	SetDrawScreen(DX_SCREEN_BACK);

	Scene scene = TITLE;

	Map map;
	Player player;

	const int ENEMY_NUM = 5;
	Light light[ENEMY_NUM];

	int goalX = 11 * 64;
	int goalY = 9 * 64;

	int gameOverTimer = 0;
	bool isGameOver = false;

	int fade = 255;
	bool fadeIn = true;
	                
	while (ProcessMessage() == 0)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
		ClearDrawScreen();

		if (scene == TITLE)
		{
			DrawString(300, 250, "SHADOW LABYRINTH", GetColor(255, 255, 255));

			if (CheckHitKey(KEY_INPUT_SPACE))
			{
				scene = GAME;
				fadeIn = true;

				player = Player();

				light[0].SetPosition(200, 200);
				light[1].SetPosition(600, 200);
				light[2].SetPosition(400, 500);
				light[3].SetPosition(700, 500);
				light[4].SetPosition(100, 400);
				light[5].SetPosition(800, 600);


				isGameOver = false;
			}
		}
		else if (scene == GAME)
		{
			map.Draw();

			DrawBox(goalX, goalY, goalX + 64, goalY + 64, GetColor(0, 255, 0), TRUE);

			for (int i = 0; i < ENEMY_NUM; i++)
			{
				light[i].Update(map, player.GetX(), player.GetY());
				light[i].Draw();
			}

			if (!isGameOver)
			{
				player.Update(map);
			}
			player.Draw();

			for (int i = 0; i < ENEMY_NUM; i++)
			{
				if (!isGameOver &&
					light[i].CheckHit(player.GetX(), player.GetY()))
				{
					isGameOver = true;

					StopSoundMem(bgmHandle);                
				/*	PlaySoundMem(gameoverSE, DX_PLAYTYPE_BACK); */
				}
			}

			if (isGameOver)
			{
				DrawString(420, 300, "GAME OVER", GetColor(255, 0, 0));

				if (CheckHitKey(KEY_INPUT_SPACE))
				{
					scene = TITLE;

					PlaySoundMem(bgmHandle, DX_PLAYTYPE_LOOP);
				}
			}

			if (!isGameOver &&
				player.GetX() > goalX &&
				player.GetX() < goalX + 64 &&
				player.GetY() > goalY &&
				player.GetY() < goalY + 64)
			{
				if (map.GetStage() == 1)
				{
					map.NextStage();
					player = Player();
				}
				else
				{
					scene = CLEAR;   
				}
			}
		}
		else if (scene == CLEAR)
		{
			DrawString(300, 400, "ALL CLEAR!", GetColor(255, 255, 255));

			if (CheckHitKey(KEY_INPUT_LSHIFT)||CheckHitKey(KEY_INPUT_RSHIFT))
			{
				scene = TITLE;

				map.ResetStage();
				player = Player();

				PlaySoundMem(bgmHandle, DX_PLAYTYPE_LOOP);
			}
		}

		// フェード
		if (fadeIn)
		{
			fade -= 10;
			if (fade <= 0)
			{
				fade = 0;
				fadeIn = false;
			}
		}


		SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade);
		DrawBox(0, 0, 960, 704, GetColor(0, 0, 0), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		ScreenFlip();
	}

	DeleteSoundMem(bgmHandle);
	/*DeleteSoundMem(gameoverSE);*/
	DxLib_End();
	return 0;
}