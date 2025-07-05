#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Setting : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

private:
    // UI Elements
    cocos2d::ui::Button* btBack;
    cocos2d::ui::Slider* volumeSlider0;
    cocos2d::ui::Slider* effectSlider;
    cocos2d::ui::Button* langDropdown;

    // UI setup methods
    void creatBackgroud(float x, float y);;
    void createButton(float x, float y);
    void createSlider(float x, float y);

    void setVolumeBackgroundMusic();
    void setVolumeSFX();
    void clickBtBack();

    // implement the "static create()" method manually
    CREATE_FUNC(Setting);
};

#endif // __SETTING_SCENE_H__
