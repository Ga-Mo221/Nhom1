#include "ui/CocosGUI.h"
#include "ui/UIEditBox/UIEditBox.h"
#include "Scenes/SceneManager/ChangeScene.h"
#include "Scenes/MainMenu/MainMenu.h"
#include "AudioManager/AudioManager.h"
#include "NewGameV2.h"
#include "GameManager/GameManager.h"
#include "gameplay2.h"

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
    createTextField(visibleSize.width / 2, visibleSize.height / 2);
    clickBtBack();
	clickBtFlag1();
	clickBtFlag2();
	clickBtMap1();
	clickBtMap2();
	clickBtMap3();
    clickBtStats();
	PickFlag(flag);
	LoadMap(map);
    return true;
}


void NewGameV2::creatBackgroud(float x, float y) {

    auto bg = Sprite::create("BG.png");
    if (bg != nullptr) {
        bg->setPosition(x, y);
        bg->setScale(1.35);
        this->addChild(bg);
    }
    else {
        CCLOG("khong tim thay file");
    }

    auto logoTwoPl = Sprite::create("two/logoTwoPlayer.png");
    if (logoTwoPl != nullptr) {
        logoTwoPl->setPosition(x, y);
        logoTwoPl->setScale(2.35);
        logoTwoPl->setPosition(x, y + y * 0.65);
        this->addChild(logoTwoPl);
    }
    else {
        CCLOG("khong tim thay file");
    }

    auto player1 = Sprite::create("two/Player1_.png");
    if (player1 != nullptr) {
        player1->setPosition(x, y);
        player1->setScale(2.35);
        player1->setPosition(x - x * 0.48, y + y * 0.41);
        this->addChild(player1);
    }
    else {
        CCLOG("khong tim thay file");
    }

    auto player2 = Sprite::create("two/Player2_.png");
    if (player2 != nullptr) {
        player2->setPosition(x, y);
        player2->setScale(2.35);
        player2->setPosition(x - x * 0.48, y + y * 0.25);
        this->addChild(player2);
    }
    else {
        CCLOG("khong tim thay file");
    }

    auto setcoler = Sprite::create("two/setcoler.png");
    if (setcoler != nullptr) {
        setcoler->setPosition(x, y);
        setcoler->setScale(2.35);
        setcoler->setPosition(x - x * 0.48, y + y * -0.15);
        this->addChild(setcoler);
    }
    else {
        CCLOG("khong tim thay file");
    }

    auto thanhgo = Sprite::create("two/thanhgo.png");
    if (thanhgo != nullptr) {
        thanhgo->setPosition(x, y);
        thanhgo->setScale(2.34);
        thanhgo->setPosition(x - x * 0.03, y + y * -0.33);
        this->addChild(thanhgo);
    }
    else {
        CCLOG("khong tim thay file");
    }
}

void NewGameV2::createButton(float x, float y) {
    btBack = ui::Button::create("backbt.png", "backbtsel.png");
    btBack->setScale(2.35);
    btBack->setPosition(Vec2(x -  x * 0.8, y + y * 0.9));
	this->addChild(btBack);

    btMap1 = ui::Button::create("one/map5x6.png", "one/map5x6dark.png");
    btMap1->setScale(2.35);
    btMap1->setPosition(Vec2(x - x * 0.55, y + y * 0.05));
    this->addChild(btMap1);

    btMap2 = ui::Button::create("two/map6x7.png", "two/map6x7dark.png");
    btMap2->setScale(2.35);
    btMap2->setPosition(Vec2(btMap1->getPosition().x + 150, btMap1->getPosition().y));
    this->addChild(btMap2);

    btMap3 = ui::Button::create("two/map7x8.png", "two/map7x8dark.png");
    btMap3->setScale(2.35);
    btMap3->setPosition(Vec2(btMap2->getPosition().x + 150, btMap2->getPosition().y));
    this->addChild(btMap3);

    btFlag1 = ui::Button::create("two/flag1V1.png", "two/flag1V2.png");
    btFlag1->setScale(2.35);
    btFlag1->setPosition(Vec2(x - x * 0.25, y + y * -0.39));
    this->addChild(btFlag1);

    btFlag2 = ui::Button::create("two/flag2V1.png", "two/flag2V2.png");
    btFlag2->setScale(2.35);
    btFlag2->setPosition(Vec2(btFlag1->getPosition().x + 140, btFlag1->getPosition().y));
    this->addChild(btFlag2);

    btStats = ui::Button::create("two/stats.png", "two/statsdark.png");
    btStats->setScale(2.35);
    btStats->setPosition(Vec2(x, y + y * -0.7));
    this->addChild(btStats);

}

void NewGameV2::createTextField(float x, float y) {
    CCLOG("hh");
    tfPlayer1 = ui::TextField::create("Name1", "fonts/Marker Felt.ttf", 32);
    tfPlayer1->setPosition(Vec2(x + x * 0.22, y + y * 0.42));
    tfPlayer1->setMaxLengthEnabled(true);
    tfPlayer1->setMaxLength(12);
    tfPlayer1->setTextColor(Color4B::WHITE);
	//GameManager::getInstance()->setnameplayer1(tfPlayer1->getString());
    this->addChild(tfPlayer1);

    tfPlayer2 = ui::TextField::create("Name2", "fonts/Marker Felt.ttf", 32);
    tfPlayer2->setPosition(Vec2(x + x * 0.22, y + y * 0.26));
    tfPlayer2->setMaxLengthEnabled(true);
    tfPlayer2->setMaxLength(12);
    tfPlayer2->setTextColor(Color4B::WHITE);
	//GameManager::getInstance()->setnameplayer2(tfPlayer2->getString());
    this->addChild(tfPlayer2);
}

void NewGameV2::clickBtFlag1() {
    btFlag1->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->flag = "flag1";
        PickFlag(this->flag);
        GameManager::getInstance()->setclflag(this->flag);
        });
}

void NewGameV2::clickBtFlag2() {
    btFlag2->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->flag = "flag2";
        PickFlag(this->flag);
        GameManager::getInstance()->setclflag(this->flag);
        });
}

void NewGameV2::clickBtMap1() {
    btMap1->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->map = "5x6";
        LoadMap(this->map);
        GameMod mod;
        mod.setMod(GameMod::MODE_5x6);
        GameManager::getInstance()->startGame(mod);
        });
}

void NewGameV2::clickBtMap2() {
    btMap2->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->map = "6x7";
        LoadMap(this->map);
        GameMod mod;
        mod.setMod(GameMod::MODE_6x7);
        GameManager::getInstance()->startGame(mod);
        });
}

void NewGameV2::clickBtMap3() {
    btMap3->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->map = "7x8";
        LoadMap(this->map);
        GameMod mod;
        mod.setMod(GameMod::MODE_7x8);
        GameManager::getInstance()->startGame(mod);
        });
}

void NewGameV2::PickFlag(const std::string& flag) {
    btFlag1->loadTextures("two/flag1V1.png", "one/flag1V2.png");
    btFlag2->loadTextures("two/flag2V1.png", "one/flag2V2.png");
    if (flag == "flag1") {
        btFlag1->loadTextures("two/flag1V2.png", "two/flag1V1.png");
    }
    else if (flag == "flag2") {
        btFlag2->loadTextures("two/flag2V2.png", "two/flag2V1.png");
    }
}

void NewGameV2::LoadMap(const std::string& map) {
    btMap1->loadTextures("one/map5x6.png", "one/map5x6dark.png");
    btMap2->loadTextures("one/map6x7.png", "one/map6x7dark.png");
    btMap3->loadTextures("one/map7x8.png", "one/map7x8dark.png");
    if (map == "5x6") {
        btMap1->loadTextures("one/map5x6dark.png", "one/map5x6.png");
    }

    else if (map == "6x7") {
        btMap2->loadTextures("one/map6x7dark.png", "one/map6x7.png");
    }

    else if (map == "7x8") {
        btMap3->loadTextures("one/map7x8dark.png", "one/map7x8.png");
    }
}

void NewGameV2::clickBtStats() {
    btStats->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        GameManager::getInstance()->setnameplayer1(tfPlayer1->getString());
		GameManager::getInstance()->setnameplayer2(tfPlayer2->getString());
        ChangeScene::ChangeScenes(gameplay2::createScene());
        });
}

void NewGameV2::clickBtBack() {
    btBack->addClickEventListener([](Ref* sender) {
        AudioManager::playClickSound();
        ChangeScene::ChangeScenes(MainMenu::createScene());
        });
}