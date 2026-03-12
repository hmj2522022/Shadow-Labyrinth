#include "Light.h"
#include "DxLib.h"

void Light::Update()
{
	timer++;

	if (timer > 120)
	{
		direction++;
		timer = 0;

		if (direction > 3)
		{
			direction = 0;
		}
	}
}

void Light::Draw()
{
	DrawCircle(enemyX, enemyY, 10, GetColor(255, 0, 0), TRUE);

	if (direction == 0)
		DrawLine(enemyX, enemyY, enemyX + 200, enemyY, GetColor(255, 255, 0));

	if (direction == 1)
		DrawLine(enemyX, enemyY, enemyX, enemyY + 200, GetColor(255, 255, 0));

	if (direction == 2)
		DrawLine(enemyX, enemyY, enemyX - 200, enemyY, GetColor(255, 255, 0));

	if (direction == 3)
		DrawLine(enemyX, enemyY, enemyX, enemyY - 200, GetColor(255, 255, 0));
}