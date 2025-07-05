#ifndef  _AUDIOMANAGER__H_
#define  _AUDIOMANAGER__H_

#include <string>

class AudioManager {
public:
    static void init();
    static void playBackgroundMusic(const std::string& file, bool loop = true);
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

#endif //_AUDIOMANAGER__H_