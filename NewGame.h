#ifndef __NEWGAME_SCENE_H__
#define __NEWGAME_SCENE_H__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

class NewGame : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    

private:
    void creatBackgroud(float x, float y);

    void createButton(float x, float y);

    void clickBtBack();

    void clickBtonePlayer();

	void clickBtTwoPlayer();

    cocos2d::ui::Button* btBack;

	cocos2d::ui::Button* btOnePlayer;

	cocos2d::ui::Button* btTwoPlayer;
    
    // implement the "static create()" method manually
    CREATE_FUNC(NewGame);
};

#endif // __NEWGAME_SCENE_H__
