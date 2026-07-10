#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include <memory>

class Field : public GameObject
{
public:
	Field(int stage);
	~Field();
	void Update() override;
	void Draw() override;

	int HitCheck(int x, int y);
	int HitCheckRight(int px, int py);
	int HitCheckLeft(int px, int py);
	int HitCheckUp(int px, int py);
	int HitCheckDown(int px, int py);
private:
	int WallImage;
	int redImage;
	int blueImage;

	int x, y;
};