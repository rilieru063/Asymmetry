#pragma once
#include "../Library/GameObject.h"
#include "Field.h"

class Player :public GameObject
{
public:
	Player(int x, int y,int Image);
	~Player();
	void Update() override;
	void Draw() override;
private:
	void Move(int dx, int dy);

	int PlayerImage;
	int px, py;
};