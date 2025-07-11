﻿#include "Scenes/Continue/Continue.h"
#include "ui/CocosGUI.h"
#include "Scenes/SceneManager/ChangeScene.h"
#include "Scenes/MainMenu/MainMenu.h"
#include "gameplay1.h"
#include "AudioManager/AudioManager.h"
#include "GameManager/GameManager.h"

USING_NS_CC;

Scene* Gameplay1::createScene()
{
    return Gameplay1::create();
}


// on "init" you need to initialize your instance
bool Gameplay1::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    AudioManager::playBackgroundMusic("nhacplay.mp3");

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    creatBackgroud(visibleSize.width / 2, visibleSize.height / 2);
    createButton(visibleSize.width / 2, visibleSize.height / 2);
    clickBtBack();
    CCLOG("%d x %d", GameManager::getInstance()->getRows(), GameManager::getInstance()->getCols());
    CCLOG("%d x %d", GameManager::getInstance()->flag1, GameManager::getInstance()->flag2);
	CCLOG("Difficulty: %s", GameManager::getInstance()->getAI().c_str());
	return true;
}


void Gameplay1::creatBackgroud(float x, float y) {
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

void Gameplay1::createButton(float x, float y) {
    btBack = ui::Button::create("backbt.png", "backbtsel.png");
    btBack->setScale(2.35);
    btBack->setPosition(Vec2(x - x * 0.8, y + y * 0.9));
    this->addChild(btBack);
}

void Gameplay1::clickBtBack() {
    btBack->addClickEventListener([](Ref* sender) {
        AudioManager::playBackgroundMusic("nhac.mp3");
        AudioManager::playClickSound();
        ChangeScene::ChangeScenes(MainMenu::createScene());
        });
}