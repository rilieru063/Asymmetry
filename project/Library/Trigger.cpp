#include <sstream>
#include <DxLib.h>
#include "Trigger.h"
#include "time.h"

namespace KeyBuffer
{
    static bool currentKey[0xff];
    static bool previousKey[0xff];
}


/**********************/
/***    KeyUtility  ***/
/**********************/

void KeyTrigger::Update()
{
    for (int i = 0; i < 0xff; i++)
    {
        KeyBuffer::previousKey[i] = KeyBuffer::currentKey[i];
        KeyBuffer::currentKey[i] = (CheckHitKey(i) != 0);
    }
}

//  キー関連処理の初期化
void KeyTrigger::Init()
{
    for (int i = 0; i < 0xff; i++)
    {
        KeyBuffer::currentKey[i] = false;
        KeyBuffer::previousKey[i] = false;
    }
}

//  キー入力のトリガー取得
bool KeyTrigger::CheckTrigger(int keyCode)
{
    return KeyBuffer::currentKey[keyCode] &&
        !KeyBuffer::previousKey[keyCode];
}