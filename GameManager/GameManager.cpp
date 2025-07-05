#include "GameManager.h"

GameManager* GameManager::s_instance = nullptr;

GameManager::GameManager()
{
    _mod.setMod(GameMod::MODE_5x6);

    _rows = _mod.getRows();
    _cols = _mod.getCols();

    _board = vector<vector<int>>(_rows, vector<int>(_cols, 0));
}

GameManager::~GameManager()
{
    // Dọn dẹp nếu cần
}

GameManager* GameManager::getInstance()
{
    if (!s_instance)
    {
        s_instance = new GameManager();
    }
    return s_instance;
}

void GameManager::destroyInstance()
{
    if (s_instance)
    {
        delete s_instance;
        s_instance = nullptr;
    }
}

void GameManager::startGame()
{
    // Logic bắt đầu game
}

void GameManager::restartGame()
{
    // Logic chơi lại từ đầu
}

void GameManager::pauseGame()
{
    // Logic tạm dừng game
}

void GameManager::resumeGame()
{
    // Logic tiếp tục game
}

void GameManager::endGame()
{
    // Logic kết thúc game
}

bool GameManager::dropToken(int col)
{
    // Người chơi thả quân vào cột -> tự động rơi xuống hàng thấp nhất
    return false;
}

bool GameManager::isColumnFull(int col) const {
    // Kiểm tra đã full cột đó chưa
    return false;
}

bool GameManager::isBoardFull() const {
    // kiểm tra toàn bộ bàn cờ đã full chưa
    return false;
}

void GameManager::resetBoard() {
    // xử lý xóa hết ball để người chơi chơi lại
}

int GameManager::getCurrentPlayer() const {
    // Lấy ID người chơi hiện tại (1 hoặc 2)
    return 0;
}     

void GameManager::switchPlayer() {
    // Đổi lượt
}

bool GameManager::checkVictory(int row, int col, int player) {
    // Kiểm tra 4 ô liên tiếp từ vị trí vừa đặt
    return false;
}

int GameManager::countDirection(int row, int col, int dRow, int dCol, int player) {
    // Đếm ô theo hướng
    return 0;
}

int GameManager::getCellValue(int row, int col) const {
    // Truy xuất giá trị ô để vẽ UI
    return 0;
}

int GameManager::getRows() const {
    return 0;
}

int GameManager::getCols() const {
    return 0;
}