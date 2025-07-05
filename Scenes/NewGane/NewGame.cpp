#include "NewGame.h"
#include "ui/CocosGUI.h"
#include "Scenes/SceneManager/ChangeScene.h"
#include "Scenes/MainMenu/MainMenu.h"
#include "Scenes/NewGane/Player_bot/NewGameV1.h"
#include "Scenes/NewGane/Player_Player/NewGameV2.h"
#include "AudioManager/AudioManager.h"

USING_NS_CC;

Scene* NewGame::createScene()
{
    return NewGame::create();
}


// on "init" you need to initialize your instance
bool NewGame::init()
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
    clickBtonePlayer();
	clickBtTwoPlayer();
    return true;
}


void NewGame::creatBackgroud(float x, float y) {
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

void NewGame::createButton(float x, float y) {
    btBack = ui::Button::create("backbt.png", "backbtsel.png");
    btBack->setScale(2.35);
    btBack->setPosition(Vec2(x - x * 0.8, y + y * 0.9));
    
	btOnePlayer = ui::Button::create("BTOnePlayer.png", "BTOnePlayerDark.png");
	btOnePlayer->setScale(1.35);
	btOnePlayer->setPosition(Vec2(x, y + y * 0.3));

    btTwoPlayer = ui::Button::create("BTTwoPlayer.png", "BTTwoPlayerDark.png");
	btTwoPlayer->setScale(1.35);
    btTwoPlayer->setPosition(Vec2(btOnePlayer->getPosition().x, btOnePlayer->getPosition().y - 100.0));

    this->addChild(btBack);
    this->addChild(btOnePlayer);
	this->addChild(btTwoPlayer);
}

void NewGame::clickBtBack() {
    btBack->addClickEventListener([](Ref* sender) {
        AudioManager::playClickSound();
        ChangeScene::ChangeScenesL(MainMenu::createScene());
        });
}

void NewGame::clickBtonePlayer() {
    btOnePlayer->addClickEventListener([](Ref* sender) {
        AudioManager::playClickSound();
        ChangeScene::ChangeScenes(NewGameV1::createScene());
        });
}

void NewGame::clickBtTwoPlayer() {
    btTwoPlayer->addClickEventListener([](Ref* sender) {
        AudioManager::playClickSound();
        ChangeScene::ChangeScenes(NewGameV2::createScene());
        });
}
