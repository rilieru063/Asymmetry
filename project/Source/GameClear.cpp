#include "GameClear.h"
#include "StageNumber.h"

#include "../Library/Trigger.h"
#include <cstdio>

GameClear::GameClear()
{
}

GameClear::~GameClear()
{
}

void GameClear::Update()
{
    StageNumber* sn = FindGameObject<StageNumber>();

    if (CheckHitKey(KEY_INPUT_T))
    {
        SceneManager::Exit();
    }
    if (KeyTrigger::CheckTrigger(KEY_INPUT_ESCAPE))
    {
        SceneManager::ChangeScene("TITLE");
    }
    if (KeyTrigger::CheckTrigger(KEY_INPUT_SPACE))
    {
        int nextStage = sn->stagenum + 1;

        char filename[60];
        sprintf_s<60>(filename, "data/Stage_%02d.csv", nextStage);

        // 次のステージが存在するか確認
        FILE* fp = nullptr;

        if (fopen_s(&fp, filename, "r") == 0)
        {
            // ファイルが存在する
            fclose(fp);

            sn->stagenum = nextStage;
            sn->Clear = false;

            SceneManager::ChangeScene("PLAY");
        }
        else
        {
            // 次のステージが存在しない
            SceneManager::ChangeScene("TITLE");
        }
    }
}

void GameClear::Draw()
{
    DrawExtendString(660, 300, 5, 5, "StageClear!", GetColor(255, 255, 255));
    DrawExtendString(300, 800, 3, 3, "Press the ESCAPE", GetColor(255, 255, 255));
    DrawExtendString(350, 860, 3, 3, "to the Title", GetColor(255, 255, 255));
    DrawExtendString(1100, 800, 3, 3, "Press the SPACE", GetColor(255, 255, 255));
    DrawExtendString(1085, 860, 3, 3, "to the NextStage", GetColor(255, 255, 255));
}
