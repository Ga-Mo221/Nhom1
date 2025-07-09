#include "GameManager.h"
#include <CCPlatformMacros.h>

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

void GameManager::startGame(GameMod mod)
{
	_mod = mod; // Lưu chế độ chơi
    _rows = _mod.getRows();
    _cols = _mod.getCols();

    _board = vector<vector<int>>(_rows, vector<int>(_cols, 0));
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

bool GameManager::dropToken(int col){

    if (col < 0 || col >= _cols || isColumnFull(col))
        return false;

    for (int row = _rows - 1; row >= 0; --row)
    {
		if (_board[row][col] == 0) // ở đây ô rỗng là 0 player 1 là 1 player 2 là 2, tương tự thì bot nõ cũng dống như player 2 là số 2
        {
            _board[row][col] = getCurrentPlayer(); 
            return true;
        }
    }

    return false;
}

bool GameManager::isColumnFull(int col) const{

    if (col < 0 || col >= _cols)
        return true;

	return _board[0][col] != 0;// nó check trực tiếp ô 0 của row 0 nếu ô này khác 0 thì cột này đã đầy

    return false;
}

bool GameManager::isBoardFull() const {

    for (int col = 0; col < _cols; ++col)
    {
		if (!isColumnFull(col))// check từng cột nếu có cột nào không đầy thì return false nếu đã đầy thì return true
            return false;
    }

    return true;
}

void GameManager::resetBoard() {

    for (int row = 0; row < _rows; ++row)
    {
        for (int col = 0; col < _cols; ++col)
        {
			_board[row][col] = 0; // Đặt lại tất cả ô về trạng thái rỗng
        }
    }
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
    return _rows;
}

int GameManager::getCols() const {
    return _cols;
}

void GameManager::setclflag(string fl1) {
    if (fl1 == "flag1")
    {
        flag1 = 1;
        flag2 = 2;
    }
    else if (fl1 == "flag2")
    {
        flag1 = 2;
        flag2 = 1;
    }
}

void GameManager::setAI(const std::string& AI) {
    if (AI == "easy" || AI == "normal" || AI == "hard")
        _difficulty = AI;
}

std::string GameManager::getAI() const {
    return _difficulty;
}

string GameManager::getNamePlayer1() const {
    return _namePlayer1;
}

string GameManager::getNamePlayer2() const {
    return _namePlayer2;
}

void GameManager::setnameplayer1(const std::string& name) {
    
	_namePlayer1 = name;
    CCLOG("Name player 1 %s", _namePlayer1);
}

void GameManager::setnameplayer2(const std::string& name) {
	_namePlayer2 = name;
	CCLOG("Name player 2 %s", _namePlayer2);
}

