#include "DxLib.h"
#include "SceneManager.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager scene;

	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && ScreenFlip() == 0) {
		scene.Update();
		scene.Draw();
	}

	DxLib_End();
	return 0;
}
