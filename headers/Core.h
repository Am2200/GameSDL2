#ifndef CMAKETEST_CORE_H
#define CMAKETEST_CORE_H

#include "FullSDL.h"
#include <string>
#include "ProcessManager.h"

/**
 * Пока не знаю, что делать с process_manager. Вроде штука нужная, а нормально написать не могу ;)
 */
class Core {
public:
    Core();
    ~Core();
    void Init();
    void Run();
    void Shutdown();
    void ResizeWindow(int, int);
    void setWindowFullScreen(bool);
    //void CheckInit();
    SDL_Window *getWindowLink();
    //ProcessManager<bool>* getManager();
private:
    int m_Width;
    int m_Height;
    std::string m_WindowName;
    bool m_Fullscreen = false;
    SDL_Window *window = nullptr;
    //ProcessManager<bool> *state = nullptr;
};

#endif //CMAKETEST_CORE_H