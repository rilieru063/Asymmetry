#include "Player.h"
#include "Field.h"
#include "../Library/Trigger.h"

Player::Player(int x, int y)
{
	PlayerImage = LoadGraph("data/Image/Red_Player.png");
	px = x;
	py = y;
}

Player::~Player()
{
}

void Player::Update()
{
    Field* field = FindGameObject<Field>();

    if (KeyTrigger::CheckTrigger(KEY_INPUT_W) ||
        KeyTrigger::CheckTrigger(KEY_INPUT_UP)) {
        py -= 64;
    }

    if (KeyTrigger::CheckTrigger(KEY_INPUT_A) ||
        KeyTrigger::CheckTrigger(KEY_INPUT_LEFT)) {
        px -= 64;
    }

    if (KeyTrigger::CheckTrigger(KEY_INPUT_S) ||
        KeyTrigger::CheckTrigger(KEY_INPUT_DOWN)) {
        py += 64;
    }

    if (KeyTrigger::CheckTrigger(KEY_INPUT_D) ||
        KeyTrigger::CheckTrigger(KEY_INPUT_RIGHT))
    {
        int push1 = field->HitCheckRight(px + 64 + 55, py + 28);

        if (push1 == 0)
        {
            px += 64;
        }
    }
}

void Player::Draw()
{
	DrawExtendGraph(px, py, px + 64, py + 64, PlayerImage, 1);
}
