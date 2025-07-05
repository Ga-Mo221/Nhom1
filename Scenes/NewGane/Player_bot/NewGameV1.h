#ifndef __NEWGAMEV1_SCENE_H__
#define __NEWGAMEV1_SCENE_H__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

class NewGameV1 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    

private:
    void creatBackgroud(float x, float y);

    void createButton(float x, float y);

    void clickBtBack();
	void clickBtEasy();
    void clickBtNormal();
	void clickBtHard();
	void clickBtFlag1();
	void clickBtFlag2();
	void clickBtMap1();
	void clickBtMap2();
	void clickBtMap3();
	void clickBtStats();

    void LoadmodAI(const std::string& difficulty);
	void PickFlag(const std::string& flag);
	void LoadMap(const std::string& map);
	//void PickMap1(const std::string& map);
    cocos2d::ui::Button* btBack;
	cocos2d::ui::Button* btEasy;
	cocos2d::ui::Button* btNormal;
	cocos2d::ui::Button* btHard;
	cocos2d::ui::Button* btFlag1;    
	cocos2d::ui::Button* btFlag2;  
	cocos2d::ui::Button* btMap1;
	cocos2d::ui::Button* btMap2;
	cocos2d::ui::Button* btMap3;
	cocos2d::ui::Button* btStats;
	// Default values for the game settings

	std::string flag = "flag1";
    std::string difficulty = "easy";
	std::string map = "6x7";
    // implement the "static create()" method manually
    CREATE_FUNC(NewGameV1);
};

#endif // __CONTINUE_SCENE_H__
