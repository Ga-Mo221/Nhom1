#pragma once
#include <string>

class AudioManager {
public:
    static void init();
    static void setMusicID(int id);
    static void playBackgroundMusic(const std::string& file, bool loop = true);

    static int getMusicID();
    static void setVolume(float volume);
    static float getVolume(); 

    static void playClickSound(); 
    static void setEffectVolume(float volume); 
    static float getEffectVolume(); 


private:
    static int musicID;
    static float musicVolume;
    static float effectVolume; // ? New
};
