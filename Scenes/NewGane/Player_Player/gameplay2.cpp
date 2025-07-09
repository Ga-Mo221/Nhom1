#include "ui/CocosGUI.h"
#include "Scenes/SceneManager/ChangeScene.h"
#include "AudioManager/AudioManager.h"
#include "Scenes/MainMenu/MainMenu.h"
#include "GameManager/GameManager.h"
#include "gameplay2.h"
#include "GameManager/GameManager.h"

USING_NS_CC;

Scene* gameplay2::createScene()
{
    return gameplay2::create();
}


// on "init" you need to initialize your instance
bool gameplay2::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    creatBackgroud(visibleSize.width / 2, visibleSize.height / 2);
    createButton(visibleSize.width / 2, visibleSize.height / 2);
    CCLOG("%d x %d", GameManager::getInstance()->getRows(), GameManager::getInstance()->getCols());
    CCLOG("%d x %d", GameManager::getInstance()->flag1, GameManager::getInstance()->flag2);   
    CCLOG("name 1: %s x name 2: %s", GameManager::getInstance()->getNamePlayer1().c_str(), GameManager::getInstance()->getNamePlayer2().c_str());
    clickBtBack();
    return true;
}


void gameplay2::creatBackgroud(float x, float y) {
    // nền
    auto bg = Sprite::create("BG.png");
    if (bg != nullptr) {
        bg->setPosition(x, y);
        bg->setScale(1.35);
        this->addChild(bg);
    }
    else {
        CCLOG("khong tim thay file");
    }
}

void gameplay2::createButton(float x, float y) {
    btBack = ui::Button::create("backbt.png", "backbtsel.png");
    btBack->setScale(2.35);
    btBack->setPosition(Vec2(x - x * 0.8, y + y * 0.9));
    
    
    this->addChild(btBack);
}

void gameplay2::clickBtBack() {
    btBack->addClickEventListener([](Ref* sender) {
        AudioManager::playClickSound();
        ChangeScene::ChangeScenes(MainMenu::createScene());
        });
}