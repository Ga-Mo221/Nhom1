#include "AudioManager.h"
#include "audio/include/AudioEngine.h"
#include "base/CCUserDefault.h" 
int AudioManager::musicID = -1;
float AudioManager::musicVolume = 1.0f;
float AudioManager::effectVolume = 1.0f;

void AudioManager::init() {
    musicVolume = cocos2d::UserDefault::getInstance()->getFloatForKey("musicVolume", 1.0f);
    effectVolume = cocos2d::UserDefault::getInstance()->getFloatForKey("effectVolume", 1.0f);
}

void AudioManager::playBackgroundMusic(const std::string& file, bool loop /* = true */) {
    // Nếu có nhạc đang phát thì dừng
    if (musicID != -1) {
        cocos2d::AudioEngine::stop(musicID);
        musicID = -1;
    }
    musicID = cocos2d::AudioEngine::play2d(file, loop, musicVolume);
}


void AudioManager::setVolume(float volume) {
    musicVolume = volume;
    if (musicID != -1) {
        cocos2d::AudioEngine::setVolume(musicID, volume);
    }
    cocos2d::UserDefault::getInstance()->setFloatForKey("musicVolume", volume); 
    cocos2d::UserDefault::getInstance()->flush();
}


float AudioManager::getVolume() {
    return musicVolume;
}
void AudioManager::setEffectVolume(float volume) {
    effectVolume = volume;
    cocos2d::UserDefault::getInstance()->setFloatForKey("effectVolume", volume); 
    cocos2d::UserDefault::getInstance()->flush();
}

float AudioManager::getEffectVolume() {
    return effectVolume;
}

void AudioManager::playClickSound() {
    cocos2d::AudioEngine::play2d("click.mp3", false, effectVolume);
}
