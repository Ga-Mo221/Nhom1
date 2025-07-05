#ifndef __GAME_MODE_H__
#define __GAME_MODE_H__

class GameMod
{
public:
    enum ModeType
    {
        MODE_5x6,
        MODE_6x7,
        MODE_7x8
    };

    GameMod(); // mặc định MODE_5x6
    void setMod(ModeType mode);

    int getRows() const { return _rows; }
    int getCols() const { return _cols; }

private:
    int _rows;
    int _cols;
};

#endif // __GAME_MODE_H__