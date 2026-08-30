#include "GameClear.h"
#include "StageNumber.h"

GameClear::GameClear()
{
}

GameClear::~GameClear()
{
}

void GameClear::Update()
{
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
	StageNumber* sn = FindGameObject<StageNumber>();
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		sn->stagenum = 0;
	}
}

void GameClear::Draw()
{
}
