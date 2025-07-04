#include "ChangeScene.h"

void ChangeScene::ChangeScenes(cocos2d::Scene* scene) {
	auto transition = cocos2d::TransitionSlideInR::create(0.5f, scene);
	cocos2d::Director::getInstance()->replaceScene(transition);
}

void ChangeScene::ChangeScenesL(cocos2d::Scene* scene) {
	auto transition = cocos2d::TransitionSlideInL::create(0.5f, scene);
	cocos2d::Director::getInstance()->replaceScene(transition);
}