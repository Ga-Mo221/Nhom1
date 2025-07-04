#include "Setting.h"
#include "ui/CocosGUI.h"
#include "ChangeScene.h"
#include "MainMenu.h"
#include "AudioManager.h"
#include "audio/include/AudioEngine.h"
USING_NS_CC;
static int musicID = -1;
using namespace cocos2d::ui;

Scene* Setting::createScene()
{
    return Setting::create();
}

bool Setting::init()
{
    if (!Scene::init()) return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    float centerX = origin.x + visibleSize.width / 2;
    float centerY = origin.y + visibleSize.height / 2;

    creatBackgroud(centerX, centerY);
    createButton(centerX, centerY);
    clickBtBack();
    return true;
}

void Setting::creatBackgroud(float x, float y) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    auto bg = Sprite::create("BG.png");
    if (bg != nullptr) {
        bg->setPosition(x, y);
        bg->setScale(1.35);
        this->addChild(bg);
    }
    else {
        CCLOG("❌ Không tìm thấy BG.png");
    }

    // Thêm ảnh 'setting.png' ở trên
    auto settingTitle = Sprite::create("setting.png");
    if (settingTitle) {
        settingTitle->setScale(2.35);
        settingTitle->setPosition(Vec2(x, y + visibleSize.height * 0.33f));
        this->addChild(settingTitle);
    }

    // Thêm 'thanh volume.png' ở giữa
    auto volumeBar = Sprite::create("volume.png");
    if (volumeBar) {
        volumeBar->setScale(2.35);
        volumeBar->setPosition(Vec2(x, y + visibleSize.height * 0.12f));
        this->addChild(volumeBar);
    }

    auto volumeSlider0 = Slider::create();
    volumeSlider0->loadBarTexture("thanhhienm.png");                // ảnh nền
    volumeSlider0->loadSlidBallTextures("nutkeom.png");         // nút kéo
    volumeSlider0->loadProgressBarTexture("thanhkeom.png");   // phần đã kéo
    volumeSlider0->setPercent(100 * AudioManager::getVolume());
    volumeSlider0->setScale(2.35);
    volumeSlider0->setPosition(Vec2(x, y + visibleSize.height * 0.04f));
    this->addChild(volumeSlider0);

    volumeSlider0->addTouchEventListener([](Ref* sender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            auto slider = dynamic_cast<Slider*>(sender);
            float volume = slider->getPercent() / 100.0f;

            AudioManager::setVolume(volume);       
            AudioManager::playClickSound();      
        }
        });



    auto soundLang = Sprite::create("sound.png");
    if (soundLang) {
        soundLang->setScale(2.35);
        soundLang->setPosition(Vec2(x, y-50));
        this->addChild(soundLang);
    }

    auto effectSlider = Slider::create();

    effectSlider->loadBarTexture("thanhhien.png");                // ảnh nền
    effectSlider->loadSlidBallTextures("nutkeo.png");         // nút kéo
    effectSlider->loadProgressBarTexture("thanhkeo.png");   // phần đã kéo
    effectSlider->setPercent(100 * AudioManager::getEffectVolume());
    effectSlider->setScale(2.35);
    effectSlider->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 -120));
    this->addChild(effectSlider);
    effectSlider->addTouchEventListener([](Ref* sender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            auto slider = dynamic_cast<Slider*>(sender);
            float volume = slider->getPercent() / 100.0f;

            AudioManager::setEffectVolume(volume);    
            AudioManager::playClickSound();           
        }
        });
}

void Setting::createButton(float x, float y) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    

    btBack = ui::Button::create("backbt.png", "backbtsel.png");
    btBack->setScale(2.35);
    btBack->setPosition(Vec2(x - x * 0.8, y + y * 0.9));
    this->addChild(btBack);
}
    
void Setting::clickBtBack() {
    btBack->addClickEventListener([](Ref* sender) {
        CCLOG("da click back");
        AudioManager::playClickSound();
        ChangeScene::ChangeScenes(MainMenu::createScene());
        });
}
