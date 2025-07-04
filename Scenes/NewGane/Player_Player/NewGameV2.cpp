﻿#include "ui/CocosGUI.h"
#include "Scenes/SceneManager/ChangeScene.h"
#include "Scenes/MainMenu/MainMenu.h"
#include "AudioManager/AudioManager.h"
#include "NewGameV2.h"

USING_NS_CC;

Scene* NewGameV2::createScene()
{
    return NewGameV2::create();
}


// on "init" you need to initialize your instance
bool NewGameV2::init()
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


void NewGameV2::creatBackgroud(float x, float y) {
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

void NewGameV2::createButton(float x, float y) {
    btBack = ui::Button::create("backbt.png", "backbtsel.png");
    btBack->setScale(2.35);
    btBack->setPosition(Vec2(x - x * 0.8, y + y * 0.9));
    
    
    this->addChild(btBack);
}

void NewGameV2::clickBtBack() {
    btBack->addClickEventListener([](Ref* sender) {
        AudioManager::playClickSound();
        ChangeScene::ChangeScenes(MainMenu::createScene());
        });
}