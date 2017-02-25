#ifndef CMAKETEST_STATEMANAGER_H
#define CMAKETEST_STATEMANAGER_H

#include <string>
#include <iostream>
/**
 * Менеджер событий. Следит в каком состоянии сейчас находится игра
 */
class StateManager
{
public:
    StateManager();
    ~StateManager();
    void changeStatus(std::string);
    void viewStatus();
private:
    int currentStatus;
    enum status {
        Initialize = 1,
        Run = 2,
        Exit = 6
    };
};


#endif //CMAKETEST_STATEMANAGER_H
