//
// Created by Am on 25.02.2017.
//
#include <iostream>
#include "../headers/AudioCore.h"

AudioCore::AudioCore() {
    //
}

AudioCore::~AudioCore() {

}

void AudioCore::Init() {
    if(Mix_OpenAudio(AudioFrequency, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)) {
        std::cout << Mix_GetError() << std::endl;
    }
}

void AudioCore::Play(int loops) {
    Mix_PlayMusic(music, loops);
}

void AudioCore::setLoadMus(std::string path) {
    this->path = path;
    music = Mix_LoadMUS(this->path.c_str());
}

void AudioCore::setVolumeMusic(int volume) {
    Mix_VolumeMusic(volume);
}

void AudioCore::setAllConfigure(std::string path, int volume) {
    setLoadMus(path);
    setVolumeMusic(volume);
}
