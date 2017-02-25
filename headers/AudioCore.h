//
// Created by Am on 25.02.2017.
//

#ifndef CMAKETEST_AUDIOCORE_H
#define CMAKETEST_AUDIOCORE_H

#include "SDL2/SDL_mixer.h"
#include <string>

class AudioCore {
public:
    AudioCore();
    ~AudioCore();
    void Init();
    void Play(int);
    void setAllConfigure(std::string, int);
private:
    void setLoadMus(std::string);
    void setVolumeMusic(int);
    Mix_Music *music = nullptr;
    std::string path;
    const int AudioFrequency = 22600;
};


#endif //CMAKETEST_AUDIOCORE_H
