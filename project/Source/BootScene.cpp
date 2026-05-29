#include "BootScene.h"
#include "StageNumber.h"

BootScene::BootScene()
{
	new StageNumber();
}

BootScene::~BootScene()
{
}

void BootScene::Update()
{
	SetFontSize(20);
	SceneManager::ChangeScene("TITLE"); // ‹N“®‚ªI‚í‚Á‚½‚çTitle‚ğ•\¦
}

void BootScene::Draw()
{
}
