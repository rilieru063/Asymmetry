#include "Player.h"
#include "Field.h"
#include "../Library/Trigger.h"

Player::Player(int x, int y,int Image)
{
	PlayerImage = Image;
	px = x;
	py = y;
}

Player::~Player()
{
}

void Player::Update()
{
    if (KeyTrigger::CheckTrigger(KEY_INPUT_W) ||
        KeyTrigger::CheckTrigger(KEY_INPUT_UP))
    {
        Move(0, -64);
    }

    if (KeyTrigger::CheckTrigger(KEY_INPUT_A) ||
        KeyTrigger::CheckTrigger(KEY_INPUT_LEFT))
    {
        Move(-64, 0);
    }

    if (KeyTrigger::CheckTrigger(KEY_INPUT_S) ||
        KeyTrigger::CheckTrigger(KEY_INPUT_DOWN))
    {
        Move(0, 64);
    }

    if (KeyTrigger::CheckTrigger(KEY_INPUT_D) ||
        KeyTrigger::CheckTrigger(KEY_INPUT_RIGHT))
    {
        Move(64, 0);
    }
}

void Player::Draw()
{
	DrawExtendGraph(px, py, px + 64, py + 64, PlayerImage, 1);
}

void Player::Move(int dx, int dy)
{
    Field* field = FindGameObject<Field>();

    int hit = field->HitCheck(px + dx, py + dy);

    switch (hit)
    {
    case 0:     // è∞
        px += dx;
        py += dy;
        break;

    case 1:     // ï«
        break;
    }
}