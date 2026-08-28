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
    GoalIn = false;
}

void Player::Update()
{
    if (GoalIn)
        return;

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
    case 0:     // è∞
        px += dx;
        py += dy;
        break;

    case 1:     // ï«
        break;

    case 8:
    case 9:
    {
        auto keys = FindGameObjects<Key>();

        bool allKeyGet = true;

        for (auto key : keys)
        {
            if (!key->IsGet())
            {
                allKeyGet = false;
                break;
            }
        }

        if (allKeyGet)
        {
            px += dx;
            py += dy;
            GoalIn = true;

            auto players = FindGameObjects<Player>();

            bool allGoalIn = true;

            for (auto player : players)
            {
                if (!player->IsGoalIn())
                {
                    allGoalIn = false;
                    break;
                }
            }

            if (allGoalIn)
            {
                sn->Clear = true;
            }
        }

        break;
    }

    case 6:
    case 7:    //Key
        px += dx;
        py += dy;

        {
            auto keys = FindGameObjects<Key>();

            for (auto key : keys)
            {
                if (key->GetX() == px && key->GetY() == py)
                {
                    key->Get();
                }
            }
        }
        break;
    }
}