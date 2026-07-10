#include "Key.h"

Key::Key(int x,int y, KeyType keyType)
{
	kx = x;
	ky = y;
	KeyImage = LoadGraph("data/Image/Key.png");
	type = keyType;
	
	Reset();
}

Key::~Key()
{
}

void Key::Reset()
{
	KeyGet = false;
}

void Key::Update()
{
}

void Key::Draw()
{
	DrawExtendGraph(kx, ky, kx + 64, ky + 64, KeyImage, 1);
}
