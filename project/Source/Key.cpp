#include "Key.h"

Key::Key(int x,int y, KeyType keyType)
{
	kx = x;
	ky = y;
	type = keyType;
	KeyGet = false;

	if (type == KeyType::Red)
		KeyImage = LoadGraph("data/Image/Key_gold.png");
	else
		KeyImage = LoadGraph("data/Image/Key_silver.png");
	
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
    if (!KeyGet)
    {
        DrawExtendGraph(kx, ky, kx + 64, ky + 64, KeyImage, 1);
    }
}

void Key::Get()
{
	KeyGet = true;
}

bool Key::IsGet() const
{
	return KeyGet;
}

int Key::GetX() const
{
	return kx;
}

int Key::GetY() const
{
	return ky;
}