#include "Player.h"

Player::Player(int x, int y)
{
	PlayerImage = LoadGraph("data/Image/Red_Player.png");
	x = 0;
	y = 0;
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Draw()
{
	DrawExtendGraph(x * 64, y * 64, x * 64 + 64, y * 64 + 64, PlayerImage, 1);
}
