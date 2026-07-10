#include "Player.h"
#include "Field.h"
#include "Key.h"
#include "Goal.h"
#include "StageNumber.h"
#include "../Library/Trigger.h"

Player::Player(int x, int y,int Image)
{
	ResetPImage = Image;
	ResetX = x;
	ResetY = y;

    Reset();
}

Player::~Player()
{
}

void Player::Reset()
{
    px = ResetX;
    py = ResetY;
    PlayerImage = ResetPImage;
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
    StageNumber* sn = FindGameObject<StageNumber>();
    

    int hit = field->HitCheck(px + dx, py + dy);

    switch (hit)
    {
    case 0:     // °
        px += dx;
        py += dy;
        break;

    case 1:     // •Ç
        break;

    case 8:     // redgoal
        px += dx;
        py += dy;
        sn->Clear = true;
        break;
        
    case 9:     // bluegoal
        px += dx;
        py += dy;
        sn->Clear = true;
        break;

    case 10:    //Key
        px += dx;
        py += dy;

        break;
    }
}