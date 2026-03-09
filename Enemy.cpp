#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy(int x, int y) : x(x), y(y) {}

void Enemy::Update(int px, int py, int map[][20]) {
	// ‚±‚±‚É’ÇÕEUŒ‚ˆ—‚ğ’Ç‰Á‚µ‚Ä‚¢‚­
}

void Enemy::Draw() {
	DrawBox(x * 32, y * 32, x * 32 + 32, y * 32 + 32, GetColor(255, 0, 0), TRUE);
}
