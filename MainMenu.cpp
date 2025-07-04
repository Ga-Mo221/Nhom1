#include "MainMenu.h"
#include "ui/CocosGUI.h"
#include "ChangeScene.h"
#include "Continue.h"
#include "NewGame.h"
#include "Setting.h"
#include "AudioManager.h"
#include "audio/include/AudioEngine.h"

USING_NS_CC;

using namespace cocos2d::ui;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}


// on "init" you need to initialize your instance
bool MainMenu::init()
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

    // play background music
    AudioManager::init();
    AudioManager::playBackgroundMusic("nhac.mp3");


    clickBtContinue();
    clickBtNewGame();
    clickBtSetting();
    clickBtExit();
    return true;
}


void MainMenu::creatBackgroud(float x, float y) {
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

    // tên game
    auto gamename = Sprite::create("gamename.png");
    if (gamename != nullptr) {
        gamename->setPosition(x, y + y * 0.7);
        gamename->setScale(2.35);
        this->addChild(gamename);
    }
    else {
        CCLOG("khong tim thay file");
    }
}

void MainMenu::createButton(float x, float y) {
    btcontinue = ui::Button::create("continuebt.png", "continuebtsel.png");
    btcontinue->setScale(2.35);
    btcontinue->setPosition(Vec2(x, y + y * 0.3));
    
    btnewgame = ui::Button::create("newgamebt.png", "newgamebtsel.png");
    btnewgame->setScale(2.35);
    btnewgame->setPosition(Vec2(btcontinue->getPosition().x, btcontinue->getPosition().y - 100.0));

    btsetting = ui::Button::create("settingbt.png", "settingbtsel.png");
    btsetting->setScale(2.35);
    btsetting->setPosition(Vec2(btcontinue->getPosition().x, btcontinue->getPosition().y - 200.0));

    btexit = ui::Button::create("exitbt.png", "exitbtsel.png");
    btexit->setScale(2.35);
    btexit->setPosition(Vec2(btcontinue->getPosition().x, btcontinue->getPosition().y - 300.0));

    this->addChild(btcontinue);
    this->addChild(btnewgame);
    this->addChild(btsetting);
    this->addChild(btexit);
}

void MainMenu::clickBtContinue() {
    btcontinue->addClickEventListener([](Ref* sender) {
        CCLOG("da click continue");
        AudioManager::init();
        AudioManager::playBackgroundMusic("nhacplay.mp3");
        // Director::getInstance()->replaceScene(GameScene::createScene());
        ChangeScene::ChangeScenes(Continue::createScene());
        });
}

void MainMenu::clickBtNewGame() {
    btnewgame->addClickEventListener([](Ref* sender) {
        CCLOG("da click new game");
        // Director::getInstance()->replaceScene(GameScene::createScene());
        ChangeScene::ChangeScenes(NewGame::createScene());
        });
}

void MainMenu::clickBtSetting() {
    btsetting->addClickEventListener([](Ref* sender) {
        CCLOG("da click setting");
        // Director::getInstance()->replaceScene(GameScene::createScene());
        ChangeScene::ChangeScenes(Setting::createScene());
        });
}

void MainMenu::clickBtExit() {
    btexit->addClickEventListener([](Ref* sender) {
        CCLOG("da click exit");
        // Director::getInstance()->replaceScene(GameScene::createScene());
        Director::getInstance()->end();
        });
}