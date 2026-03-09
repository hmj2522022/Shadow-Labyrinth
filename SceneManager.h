#pragma once
#include "Game.h"

enum class SceneType {
	Title,
	Game,
	Clear
};

class SceneManager {
public:
	SceneManager();
	void Update();
	void Draw();

private:
	SceneType current;
	Game game;
};
