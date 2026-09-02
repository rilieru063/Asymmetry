#include "TitleScene.h"
#include "StageNumber.h"
#include "Screen.h"

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
	if (CheckHitKey(KEY_INPUT_O)) {
		SceneManager::Exit();
	}
}

void TitleScene::Draw()
{
	if (Screen::DEVELOPER_MODE == TRUE) {
		extern const char* Version();
		DrawString(0, 20, Version(), GetColor(255, 255, 255));
		DrawString(0, 0, "TITLE SCENE", GetColor(255, 255, 255));
		DrawFormatString(100, 100, GetColor(255, 255, 255), "%4.1f", 1.0f / Time::DeltaTime());
	}
	DrawExtendString(620, 300, 6, 6, "Asymmetry", GetColor(255, 255, 255));
	DrawExtendString(700, 800, 3, 3, "PUSH TO SPACE", GetColor(255, 255, 255));
}