#include "Goal.h"

Goal::Goal(int x, int y, int Image)
{
	gx = x;
	gy = y;
	GoalImage = Image;
}

Goal::~Goal()
{
}

void Goal::Update()
{
}

void Goal::Draw()
{
	DrawExtendGraph(gx, gy, gx + 64, gy + 64, GoalImage, 1);
}