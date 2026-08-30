#include "GameClear.h"
#include "StageNumber.h"
#include "Screen.h"

#include "../Library/Trigger.h"

GameClear::GameClear()
{
}

GameClear::~GameClear()
{
}

void GameClear::Update()
{
	StageNumber* sn = FindGameObject<StageNumber>();
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
	if (KeyTrigger::CheckTrigger(KEY_INPUT_SPACE)) {
		sn->stagenum++;
		sn->Clear = false;
		SceneManager::ChangeScene("PLAY");
	}
}

void GameClear::Draw()
{
	DrawString(Screen::WIDTH / 2, Screen::HEIGHT / 2, "PressSpace", GetColor(255, 255, 255));
}
