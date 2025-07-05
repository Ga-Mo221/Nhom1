#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

class MainMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    

private:
    void creatBackgroud(float x, float y);

    void createButton(float x, float y);

    void clickBtContinue();
    void clickBtNewGame();
    void clickBtSetting();
    void clickBtExit();


    cocos2d::ui::Button* btcontinue;
    cocos2d::ui::Button* btnewgame;
    cocos2d::ui::Button* btsetting;
    cocos2d::ui::Button* btexit;
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
};

#endif // __MAINMENU_SCENE_H__
