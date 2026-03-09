#include "Game.h"

Game::Game()
	: player(2, 1), enemy(17, 1) {
}

void Game::Update() {
	// ‚±‚±‚ÉƒQ[ƒ€‚ÌXVˆ—‚ğ’Ç‰Á‚µ‚Ä‚¢‚­
}

void Game::Draw() {
	map.Draw();
	player.Draw();
	enemy.Draw();
}
