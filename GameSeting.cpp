#include "Continue.h"
#include "ui/CocosGUI.h"
#include "ChangeScene.h"
#include "MainMenu.h"
#include "gameseting.h"

USING_NS_CC;

Scene* gameseting::createScene()
{
    return gameseting::create();
}


// on "init" you need to initialize your instance
bool gameseting::init()
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
    clickBtBack();
    return true;
}


void gameseting::creatBackgroud(float x, float y) {
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

void gameseting::createButton(float x, float y) {
    btBack = ui::Button::create("backbt.png", "backbtsel.png");
    btBack->setScale(2.35);
    btBack->setPosition(Vec2(x - x * 0.8, y + y * 0.9));
    
    
    this->addChild(btBack);
}

void gameseting::clickBtBack() {
    btBack->addClickEventListener([](Ref* sender) {
        CCLOG("da click back");
        // Director::getInstance()->replaceScene(GameScene::createScene());
        ChangeScene::ChangeScenes(MainMenu::createScene());
        });
}