#include "Player.h"
#include "DxLib.h"

Player::Player(int x, int y) : x(x), y(y) {}

void Player::Update(int map[][20]) {
	// ‚±‚±‚ÉˆÚ“®ˆ—‚ğ’Ç‰Á‚µ‚Ä‚¢‚­
}

void Player::Draw() {
	DrawBox(x * 32, y * 32, x * 32 + 32, y * 32 + 32, GetColor(0, 255, 255), TRUE);
}

int Player::GetX() const { return x; }
int Player::GetY() const { return y; }
