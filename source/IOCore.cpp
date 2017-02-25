#include "../headers/IOCore.h"
#include <iostream>

IOCore::IOCore() {
    this->event = new SDL_Event();
//	this->Link = &mainLoop;
}

IOCore::~IOCore() {
    delete event;
}

void IOCore::mainLoop() {
    if(graphicCore != nullptr) {
        while (!quit) {
            inputProcess();
            graphicCore->clearRender();
            graphicCore->RenderAllTexturesInMap();
        }
    }
    else exit(0);
}

void IOCore::inputProcess() {
    while (SDL_PollEvent(event)) {
        switch (event->type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switchKey(&event->key.keysym.scancode);
                break;
            case SDL_MOUSEBUTTONDOWN:
                switchMouseButton(&event->button.button);
                break;
            case SDL_MOUSEMOTION:
                mouseMotionAction(&event->motion.x, &event->motion.y);
                break;
            case SDL_MOUSEWHEEL:
                mouseWheelAction(&event->wheel.y);
                break;
        }
    }
}


void IOCore::switchKey(SDL_Scancode *code) {
    std::cout << SDL_GetKeyName(SDL_GetKeyFromScancode(event->key.keysym.scancode)) << std::endl;
    switch (*code) {
        case SDL_SCANCODE_ESCAPE:
            quit = true;
            break;
        case SDL_SCANCODE_RIGHT:
        case SDL_SCANCODE_D:
            break;
        case SDL_SCANCODE_LEFT:
        case SDL_SCANCODE_A:
            break;
        case SDL_SCANCODE_UP:
        case SDL_SCANCODE_W:
            break;
        case SDL_SCANCODE_DOWN:
        case SDL_SCANCODE_S:
            break;
        default:
            //Move character
            break;
    }
}

void IOCore::switchMouseButton(Uint8 *codeButton) {
    switch (*codeButton) {
        case SDL_BUTTON_LEFT:
            std::cout << "Left mouse button" << std::endl;
            break;
        case SDL_BUTTON_RIGHT:
            std::cout << "Right mouse button" << std::endl;
            break;
        case SDL_BUTTON_MIDDLE:
            std::cout << "Middle mouse button" << std::endl;
            break;
    }
}

/**
 *
 * @param x - coordinate X-axis
 * @param y - coordinate Y-axis
 */
void IOCore::mouseMotionAction(Sint32 *x, Sint32 *y) {
    //std::cout << "X = " << *x << " Y = " << *y << std::endl;
}

/**
 * Maybe camera change...
 * @param y - x doesn't need. Because scrolling work only with Y-axis
 */
void IOCore::mouseWheelAction(Sint32 *y) {
    //std::cout << *y << std::endl;
}

void IOCore::setGraphicCore(GraphicCore *gc) {
    graphicCore = gc;
}
