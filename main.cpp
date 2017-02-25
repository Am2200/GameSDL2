#include "headers/FullSDL.h"
#include "headers/Core.h"
#include "headers/GraphicCore.h"
#include "headers/IOCore.h"
#include "headers/AudioCore.h"

/**
 * Что надо доделать:
 * 1) Считывание с устройств ввода/вывода
 * 2) Аудио-движок
 */

using namespace std;

/**
 * Функция, где мы вызываем нашу игру
 */
void initAll() {
    Core *core = new Core();
    GraphicCore *graphicCore = new GraphicCore();
    IOCore  *ioCore = new IOCore();
    AudioCore *audioCore = new AudioCore();
    core->Run();
    audioCore->Init();
    audioCore->setAllConfigure("C:/Users/Am/Desktop/1.mp3", 80); //Bioshock Infinite - Elisabeths Theme Piano Cover.mp3

    graphicCore->Init(core->getWindowLink());
    graphicCore->CreateTexture("C:/Users/Am/Desktop/fresh-tuxinu2.png");
    ioCore->setGraphicCore(graphicCore);
    audioCore->Play(3);
    ioCore->mainLoop();
}


int main(int argc, char *argv[]) {
    initAll();
    return 0;
}