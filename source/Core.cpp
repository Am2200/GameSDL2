#include "../headers/Core.h"
#include <iostream>

Core::Core() {
    m_Width = 1024;
    m_Height = 768;
    m_WindowName = "Game Window";
}

Core::~Core() {
    SDL_DestroyWindow(window);
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

/*
	Инициализация всех составляющих для игры
	Библиотека SDL, IMG and MIX
*/
void Core::Init() {
    try {
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
        Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
    }
    catch (int e) {
        std::cout << SDL_GetError() << " Exception" << std::endl;
        return;
    }
}

/*
	Запуск нашего окна с игрой
	(Run game)
*/
void Core::Run() {
    Init();
    window = SDL_CreateWindow(m_WindowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        SDL_Log("Window error");
        SDL_Quit();
    }
}

/*
	Выключаем игру
	(Quit game)
*/
void Core::Shutdown() {
    this->~Core();
}

/*
	Меняем размеры окна
*/
void Core::ResizeWindow(int w, int h) {
}


SDL_Window *Core::getWindowLink() {
    return window;
}

void Core::setWindowFullScreen(bool screen) {
    m_Fullscreen = screen;
    if (m_Fullscreen) {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
}
