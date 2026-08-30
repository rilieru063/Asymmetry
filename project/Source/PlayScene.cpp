#include "PlayScene.h"
#include "Field.h"
#include "StageNumber.h"

PlayScene::PlayScene()
{
	StageNumber* sn = FindGameObject<StageNumber>();
	new Field(sn->stagenum);
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	StageNumber* sn = FindGameObject<StageNumber>();
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
	if (sn->Clear == true) {
		SceneManager::ChangeScene("CLEAR");
	}
}

void PlayScene::Draw()
{
	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
