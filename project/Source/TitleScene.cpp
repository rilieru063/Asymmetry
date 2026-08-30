#include "TitleScene.h"
#include "StageNumber.h"

#include "../Library/Trigger.h"

TitleScene::TitleScene()
{
	StageNumber* sn = FindGameObject<StageNumber>();
	sn->Clear = false;
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	StageNumber* sn = FindGameObject<StageNumber>();
	if (KeyTrigger::CheckTrigger(KEY_INPUT_SPACE)) {
		sn->stagenum = 0;
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	extern const char* Version();
	DrawString(0, 20, Version(), GetColor(255,255,255));
	DrawString(0, 0, "TITLE SCENE", GetColor(255,255,255));
	DrawFormatString(100, 100, GetColor(255,255,255), "%4.1f", 1.0f / Time::DeltaTime());
	DrawString(100, 400, "Push [SPACE]Key To Play", GetColor(255, 255, 255));
}
