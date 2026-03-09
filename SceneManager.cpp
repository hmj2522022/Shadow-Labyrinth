#include "SceneManager.h"
#include "DxLib.h"

SceneManager::SceneManager() : current(SceneType::Title), game() {}

void SceneManager::Update() {
	switch (current) {
	case SceneType::Title:
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			current = SceneType::Game;
		}
		break;

	case SceneType::Game:
		game.Update();
		// ƒNƒŠƒA”»’è‚ÍŒã‚Å’Ç‰Á
		break;

	case SceneType::Clear:
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			current = SceneType::Title;
		}
		break;
	}
}

void SceneManager::Draw() {
	switch (current) {
	case SceneType::Title:
		DrawString(200, 200, "TITLE - Press SPACE", GetColor(255, 255, 255));
		break;

	case SceneType::Game:
		game.Draw();
		break;

	case SceneType::Clear:
		DrawString(200, 200, "CLEAR!", GetColor(255, 255, 0));
		break;
	}
}
