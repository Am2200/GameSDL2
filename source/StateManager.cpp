#include "../headers/StateManager.h"

StateManager::StateManager() {
    currentStatus = 0;
}

StateManager::~StateManager() {
    //nothing
}

void StateManager::changeStatus(std::string status) {
    currentStatus = Run;
}

void StateManager::viewStatus() {
    std::string message = "";
    switch (currentStatus) {
        case Initialize:
            message = "Initialize";
            break;
        case Run:
            message = "Run";
            break;
        case Exit:
            message = "Exit";
            break;
        default:
            message = "Nothing";
            break;
    }
    std::cout << message << std::endl;
}
