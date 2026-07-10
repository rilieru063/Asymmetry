#pragma once
#include "../Library/GameObject.h"
#include "Field.h"

class Player :public GameObject
{
public:
	Player(int x, int y,int Image);
	~Player();
	//void Reset(int x,int y,int Image);
	void Reset();
	void Update() override;
	void Draw() override;
private:
	void Move(int dx, int dy);

	int PlayerImage;
	int px, py;

	int ResetPImage;
	int ResetX, ResetY;
};