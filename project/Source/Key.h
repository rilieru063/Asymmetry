#pragma once
#include "../Library/GameObject.h"

enum class KeyType
{
	Red,
	Blue
};

class Key :public GameObject
{
public:
	Key(int x, int y, KeyType keyType);
	~Key();
	void Reset();
	void Update() override;
	void Draw() override;

	KeyType GetType() const { return type; }


private:
	int kx, ky;
	int KeyImage;

	bool KeyGet;

	KeyType type;
};