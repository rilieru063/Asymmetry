#pragma once
#include "../Library/GameObject.h"
#include "Field.h"

class Player :public GameObject
{
public:
	Player(int x, int y);
	~Player();
	void Update() override;
	void Draw() override;
private:
	int PlayerImage;
	int x, y;
};