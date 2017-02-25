#ifndef CMAKETEST_IOCORE_H
#define CMAKETEST_IOCORE_H

#include "FullSDL.h"
#include "GraphicCore.h"

class IOCore
{
public:
    IOCore();
    ~IOCore();
    void mainLoop();
    void (IOCore::*Link)() = &mainLoop; //Ссылка на наш меин-лууп
    void setGraphicCore(GraphicCore*);
private:
    void inputProcess();
    bool quit = false;
    void switchKey(SDL_Scancode *);
    void switchMouseButton(Uint8 *);
    void mouseMotionAction(Sint32 *, Sint32 *);
    void mouseWheelAction(Sint32 *);
    SDL_Event *event = nullptr;
    GraphicCore *graphicCore = nullptr;
};

#endif //CMAKETEST_IOCORE_H