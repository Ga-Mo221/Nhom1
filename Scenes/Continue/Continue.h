#ifndef __CONTINUE_SCENE_H__
#define __CONTINUE_SCENE_H__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

class Continue : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    

private:
    void creatBackgroud(float x, float y);

    void createButton(float x, float y);

    void clickBtBack();


    cocos2d::ui::Button* btBack;
    
    // implement the "static create()" method manually
    CREATE_FUNC(Continue);
};

#endif // __CONTINUE_SCENE_H__
