#include "Goal.h"
#include "Key.h"

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
    //auto keys = FindGameObjects<Key>();

    //bool allGet = true;

    //for (auto key : keys)
    //{
    //    if (!key->IsGet())
    //    {
    //        allGet = false;
    //        break;
    //    }
    //}

    //if (allGet)
    //{
    //    // ÉNÉäÉA
    //}
}

void Goal::Draw()
{
	DrawExtendGraph(gx, gy, gx + 64, gy + 64, GoalImage, 1);
}