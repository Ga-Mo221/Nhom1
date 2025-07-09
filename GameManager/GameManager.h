#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "GameMod.h"
#include <vector>
#include <string>
#include "cocos2d.h"

using namespace std;

class GameManager
{
public:
    // Truy cập instance duy nhất
    static GameManager* getInstance();

    // Xoá bộ nhớ nếu cần (optional)
    static void destroyInstance();

    // Quản Lý Game State
    void startGame(GameMod mod);         // Bắt đầu game
    void restartGame();       // Chơi lại game
    void endGame();           // Kết thúc game
    void pauseGame();         // Tạm dừng
    void resumeGame();        // Tiếp tục


    // Xử lý bàn cờ // Done!
    bool dropToken(int col);                // Người chơi thả quân vào cột -> tự động rơi xuống hàng thấp nhất
    bool isColumnFull(int col) const;       // Kiểm tra cột đã đầy chưa
    bool isBoardFull() const;               // Kiểm tra toàn bộ bàn cờ đầy (hòa)
    void resetBoard();                      // Reset lại bàn


    // Xử lý lượt chơi & người chơi
    int getCurrentPlayer() const;           // Lấy ID người chơi hiện tại (1 hoặc 2)
    void switchPlayer();                    // Đổi lượt


    // Kiểm tra chiến thắng
    bool checkVictory(int row, int col, int player);     // Kiểm tra 4 ô liên tiếp từ vị trí vừa đặt
    int countDirection(int row, int col, int dRow, int dCol, int player); // Đếm ô theo hướng


    // Truy cập dữ liệu để UI gọi
    int getCellValue(int row, int col) const; // Truy xuất giá trị ô để vẽ UI
    int getRows() const;
    int getCols() const;

    void setclflag(string fl1);
    int flag1 = 0;
    int flag2 = 0;

    void setAI(const std::string& AI); // dùng để lưu độ khó
    std::string getAI() const;

    string getNamePlayer1() const;
    string getNamePlayer2() const;

	void setnameplayer1(const std::string& name);
	void setnameplayer2(const std::string& name);
  

private:
    GameMod _mod;
    int _rows;
    int _cols;
    vector<vector<int>> _board;

    GameManager(); // Constructor private
    ~GameManager(); // Destructor

    // Không cho phép sao chép hoặc gán
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

    string _difficulty; 
	string _namePlayer1 = "name1";
	string _namePlayer2 = "name2";
private:
    static GameManager* s_instance;
};

#endif//__GAME_MANAGER_H__ 