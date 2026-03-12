#include "Player.h"
#include "DxLib.h"

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_W)) y -= speed;
	if (CheckHitKey(KEY_INPUT_S)) y += speed;
	if (CheckHitKey(KEY_INPUT_A)) x -= speed;
	if (CheckHitKey(KEY_INPUT_D)) x += speed;
}

void Player::Draw()
{
	DrawCircle(x, y, 10, GetColor(0, 0, 255), TRUE);
}