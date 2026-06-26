#pragma once
#include "../Library/GameObject.h"
#include "Field.h"

class Player_2 :public GameObject
{
public:
	Player_2(int x, int y);
	~Player_2();
	void Update() override;
	void Draw() override;
private:
	void Move(int dx, int dy);

	int Player_2Image;
	int px, py;
};