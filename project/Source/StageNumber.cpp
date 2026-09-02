#include "StageNumber.h"
#include "../ImGui/imgui.h"
#include "Screen.h"

StageNumber::StageNumber()
{
	DontDestroyOnSceneChange();
	stagenum = -1;
	noDeath = false;
	Clear = false;
	noSound = false;
}

void StageNumber::Update()
{
	if (CheckHitKey(KEY_INPUT_LCONTROL)) {
		if (CheckHitKey(KEY_INPUT_P)) {
			Clear = true;
		}
	}
}
void StageNumber::Draw()
{
	if (Screen::DEVELOPER_MODE == TRUE) {
		ImGui::Begin("StageNumber");
		ImGui::InputInt("StageNumber", &stagenum);
		ImGui::Checkbox("NoDeath", &noDeath);
		ImGui::Checkbox("Clear", &Clear);
		ImGui::Checkbox("NoSound", &noSound);
		ImGui::End();
	}
}