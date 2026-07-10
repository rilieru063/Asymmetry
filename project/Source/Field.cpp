#pragma once
#include "Field.h"
#include "CsvReader.h"
#include "Player.h"
#include "Goal.h"
#include "Key.h"
#include "Reset.h"
#include "StageNumber.h"
#include "../Library/Trigger.h"
#include <vector>
#include <memory>
#include <assert.h>

using namespace std;

vector<vector<int>> maps;

Field::Field(int stage)
{
	char filename[60];
	sprintf_s<60>(filename, "data/Stage_%02d.csv", stage);
	CsvReader* csv = new CsvReader(filename);
	int lines = csv->GetLines();
	maps.resize(lines);
	for (int y = 0; y < lines; y++) {
		int cols = csv->GetColumns(y);
		maps[y].resize(cols);
		for (int x = 0; x < cols; x++) {
			int num = csv->GetInt(y, x);
			maps[y][x] = num;
		}
	}

	WallImage = LoadGraph("data/Image/GrayWall.png");
	assert(WallImage > 0);
	redImage = LoadGraph("data/Image/Red_Player.png");
	blueImage = LoadGraph("data/Image/Blue_Player.png");
	redTImage = LoadGraph("data/Image/Treasure_Red.png");
	assert(redTImage > 0);
	blueTImage = LoadGraph("data/Image/Treasure_Blue.png");
	assert(blueTImage > 0);

	x = 0;
	y = 0;

	for (int y = 0; y < maps.size(); y++) {
		for (int x = 0; x < maps[y].size(); x++) {

			switch (maps[y][x]) {
			case 2:
				new Player(x * 64, y * 64, redImage);
				break;

			case 3:
				new Player(x * 64, y * 64, blueImage);
				break;

			case 6:
				new Key(x * 64, y * 64,KeyType::Red);
				break;

			case 7:
				new Key(x * 64, y * 64,KeyType::Blue);
				break;

			case 8:
				new Goal(x * 64, y * 64, redTImage);
				break;

			case 9:
				new Goal(x * 64, y * 64, blueTImage);
				break;
			}
		}
	}
}

Field::~Field()
{
}

void Field::Update()
{
	Reset* reset = FindGameObject<Reset>();
	if (KeyTrigger::CheckTrigger(KEY_INPUT_R)) {
		reset->RESET();
	}
}

void Field::Draw()
{
	for (int y = 0; y < maps.size(); y++) {
		for (int x = 0; x < maps[y].size(); x++) {
			if (maps[y][x] == 1) {
				DrawExtendGraph(x * 64, y * 64, x * 64 + 64, y * 64 + 64, WallImage, 1);
			}
		}
	}
}

int Field::HitCheck(int x, int y)
{
	int tx = x / 64;
	int ty = y / 64;

	// マップ外に出ないようにする
	if (tx < 0 || tx >= maps[0].size() ||
		ty < 0 || ty >= maps.size())
	{
		return 1;   // マップ外は壁扱い
	}

	return maps[ty][tx];
}
