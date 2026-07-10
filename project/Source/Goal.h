#pragma once
#include "../Library/GameObject.h"

class Goal :public GameObject
{
public:
	Goal(int x, int y, int Image);
	~Goal();
	void Update() override;
	void Draw()override;

private:
	int gx, gy;
	int GoalImage;
};