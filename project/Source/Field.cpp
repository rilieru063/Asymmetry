#pragma once
#include "Field.h"
#include "CsvReader.h"
#include "Player.h"
#include "StageNumber.h"

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

	x = 0;
	y = 0;

	for (int y = 0; y < maps.size(); y++) {
		for (int x = 0; x < maps[y].size(); x++) {
			if (maps[y][x] == 2) {
				new Player(x * 64, y * 64);
			}
		}
	}
}

Field::~Field()
{
}

void Field::Update()
{
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

	//DrawExtendGraph(x * 64, y * 64, x * 64 + 64, y * 64 + 64, WallImage, 1);
}
