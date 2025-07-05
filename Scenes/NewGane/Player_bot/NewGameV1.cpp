#include "NewGameV1.h"
#include "ui/CocosGUI.h"
#include "Scenes/SceneManager/ChangeScene.h"
#include "Scenes/MainMenu/MainMenu.h"
#include "Scenes/NewGane/NewGame.h"
#include "Scenes/NewGane/Player_bot/gameplay1.h"
#include "AudioManager/AudioManager.h"

USING_NS_CC;

Scene* NewGameV1::createScene()
{
    return NewGameV1::create();
}


// on "init" you need to initialize your instance
bool NewGameV1::init()
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
    clickBtEasy();
    clickBtNormal();
	clickBtHard();
    clickBtFlag1();
	clickBtFlag2();
    clickBtMap1();
	clickBtMap2();
	clickBtMap3();
	clickBtStats();

    LoadmodAI(difficulty);
	PickFlag(flag);
	LoadMap(map);
    return true;
}


void NewGameV1::creatBackgroud(float x, float y) {
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

    auto gamename = Sprite::create("one/LogoOnePlayer.png");
    if (gamename != nullptr) {
        gamename->setPosition(x, y + y * 0.65);
        gamename->setScale(2.35);
        this->addChild(gamename);
    }
    else {
        CCLOG("khong tim thay file");
    }

    auto Difficulty = Sprite::create("one/Difficulty.png");
    if (Difficulty != nullptr) {
        Difficulty->setPosition(x - x * 0.5, y + y * 0.4);
        Difficulty->setScale(2.35);
        this->addChild(Difficulty);
    }
    else {
        CCLOG("khong tim thay file");
    }

    auto SetColer = Sprite::create("one/setcoler.png");
    if (SetColer != nullptr) {
        SetColer->setPosition(x - x * 0.5, y + y * 0.03);
        SetColer->setScale(2.35);
        this->addChild(SetColer);
    }
    else {
        CCLOG("khong tim thay file");
    }

    auto ThanhGo = Sprite::create("one/thanhgo.png");
    if (ThanhGo != nullptr) {
        ThanhGo->setPosition(x - x * 0.03, y + y * -0.1);
        ThanhGo->setScale(0.6);
        this->addChild(ThanhGo);
    }
    else {
        CCLOG("khong tim thay file");
    }
}

void NewGameV1::createButton(float x, float y) {
    btBack = ui::Button::create("backbt.png", "backbtsel.png");
    btBack->setScale(2.35);
    btBack->setPosition(Vec2(x - x * 0.8, y + y * 0.9));
	this->addChild(btBack);
    
	btEasy = ui::Button::create("one/easy.png", "one/easydark.png");
	btEasy->setScale(2.35);
    btEasy->setPosition(Vec2(x - x * 0.55, y + y * 0.23));
	this->addChild(btEasy);

    btNormal = ui::Button::create("one/normal.png", "one/normaldark.png");
    btNormal->setScale(2.35);
    btNormal->setPosition(Vec2(btEasy->getPosition().x + 150 , btEasy->getPosition().y));
    this->addChild(btNormal);

    btHard = ui::Button::create("one/hard.png", "one/harddark.png");
    btHard->setScale(2.35);
    btHard->setPosition(Vec2(btNormal->getPosition().x + 150, btNormal->getPosition().y));
    this->addChild(btHard);

	btFlag1 = ui::Button::create("one/flag1.png", "one/flag1dark.png");
	btFlag1->setScale(2.35);
	btFlag1->setPosition(Vec2(x - x * 0.3, y + y * -0.2));
	this->addChild(btFlag1);

	btFlag2 = ui::Button::create("one/flag2.png", "one/flag2dark.png");
	btFlag2->setScale(2.35);
	btFlag2->setPosition(Vec2(btFlag1->getPosition().x + 180, btFlag1->getPosition().y));
	this->addChild(btFlag2);

	btMap1 = ui::Button::create("one/map5x6.png", "one/map5x6dark.png");
	btMap1->setScale(2.35);
	btMap1->setPosition(Vec2(x - x * 0.55, y + y * -0.43));
	this->addChild(btMap1);

	btMap2 = ui::Button::create("one/map6x7.png", "one/map6x7dark.png");
	btMap2->setScale(2.35);
	btMap2->setPosition(Vec2(btMap1->getPosition().x + 150, btMap1->getPosition().y));
	this->addChild(btMap2);

	btMap3 = ui::Button::create("one/map7x8.png", "one/map7x8dark.png");
	btMap3->setScale(2.35);
	btMap3->setPosition(Vec2(btMap2->getPosition().x + 150, btMap2->getPosition().y));
	this->addChild(btMap3);

    btStats = ui::Button::create("one/stats.png", "one/statsdark.png");
    btStats->setScale(2.35);
    btStats->setPosition(Vec2(x, y + y * -0.7));
    this->addChild(btStats);
}

void NewGameV1::clickBtBack() {
    btBack->addClickEventListener([](Ref* sender) {
        AudioManager::playClickSound();
        ChangeScene::ChangeScenesL(NewGame::createScene());
        });
}

void NewGameV1::clickBtEasy() {
    btEasy->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->difficulty = "easy";
        LoadmodAI(this->difficulty);
        });
}

void NewGameV1::clickBtNormal() {
    btNormal->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->difficulty = "normal";
        LoadmodAI(this->difficulty);
        });
}

void NewGameV1::clickBtHard() {
    btHard->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->difficulty = "hard";
        LoadmodAI(this->difficulty);
        });
}

void NewGameV1::clickBtFlag1() {
	btFlag1->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->flag = "flag1";
		PickFlag(this->flag);
		});
}

void NewGameV1::clickBtFlag2() {
    btFlag2->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->flag = "flag2";
        PickFlag(this->flag);
        });
}

void NewGameV1::clickBtMap1() {
    btMap1->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->map = "5x6";
        LoadMap(this->map);
        });
}

void NewGameV1::clickBtMap2() {
    btMap2->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->map = "6x7";
        LoadMap(this->map);
        });
}

void NewGameV1::clickBtMap3() {
    btMap3->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        this->map = "7x8";
        LoadMap(this->map);
      });
}

void NewGameV1::clickBtStats() {
    btStats->addClickEventListener([this](Ref* sender) {
        AudioManager::playClickSound();
        ChangeScene::ChangeScenes(Gameplay1::createScene());
        });
}

void NewGameV1::LoadmodAI(const std::string& difficulty)
{
    btEasy->loadTextures("one/easy.png", "one/easydark.png");
    btNormal->loadTextures("one/normal.png", "one/normaldark.png");
    btHard->loadTextures("one/hard.png", "one/harddark.png");

    if (difficulty == "easy") {
        btEasy->loadTextures("one/easydark.png", "one/easy.png");
    }

    else if (difficulty == "normal") {
        btNormal->loadTextures("one/normaldark.png", "one/normal.png");
    }

    else if (difficulty == "hard") {
        btHard->loadTextures("one/harddark.png", "one/hard.png");
    }
}

void NewGameV1::PickFlag(const std::string& flag) {
    btFlag1->loadTextures("one/flag1.png", "one/flag1dark.png");
    btFlag2->loadTextures("one/flag2.png", "one/flag2dark.png");
    if (flag == "flag1") {
        btFlag1->loadTextures("one/flag1dark.png", "one/flag1.png");
    }
    else if (flag == "flag2") {
        btFlag2->loadTextures("one/flag2dark.png", "one/flag2.png");
    }
}

void NewGameV1::LoadMap(const std::string& map) {
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