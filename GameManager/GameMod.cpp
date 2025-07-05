#include "GameMod.h"

GameMod::GameMod()
{
    setMod(MODE_6x7);
}

void GameMod::setMod(ModeType mode)
{
    switch (mode)
    {
    case MODE_5x6:
        _rows = 5;
        _cols = 6;
        break;
    case MODE_6x7:
        _rows = 6;
        _cols = 7;
        break;
    case MODE_7x8:
        _rows = 7;
        _cols = 8;
        break;
    default:
        _rows = 5;
        _cols = 6;
        break;
    }
}
