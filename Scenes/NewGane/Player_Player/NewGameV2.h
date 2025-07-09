#ifndef __NEWGAMEV2_SCENE_H__
#define __NEWGAMEV2_SCENE_H__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

class NewGameV2 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    

private:
    void creatBackgroud(float x, float y);

    void createButton(float x, float y);

    void createTextField(float x, float y);

    void clickBtBack();
    void clickBtFlag1();
    void clickBtFlag2();
    void clickBtMap1();
    void clickBtMap2();
    void clickBtMap3();
	void clickBtStats();

    void PickFlag(const std::string& flag);
    void LoadMap(const std::string& map);

    cocos2d::ui::Button* btBack;   
    cocos2d::ui::TextField* tfPlayer1;
    cocos2d::ui::TextField* tfPlayer2;
    cocos2d::ui::Button* btMap1;
    cocos2d::ui::Button* btMap2;
    cocos2d::ui::Button* btMap3;
    cocos2d::ui::Button* btFlag1;
    cocos2d::ui::Button* btFlag2;
    cocos2d::ui::Button* btStats;

    std::string flag = "flag1";
    std::string map = "6x7";
    // implement the "static create()" method manually
    CREATE_FUNC(NewGameV2);
};

#endif // __CONTINUE_SCENE_H__
