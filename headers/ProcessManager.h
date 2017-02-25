#ifndef CMAKETEST_PROCESSMANAGER_H
#define CMAKETEST_PROCESSMANAGER_H

/**
 * Class ProcessManager keeps pointer on ours functions
 * and on/off it
 */
#include "Stack.h"

template<typename T>
class ProcessManager {
public:
    ProcessManager() {
        stack = new Stack<T>;
    }

    ~ProcessManager() {
        delete stack;
    }

    void Push(T x) {
        stack->push(x);
    }

    elementStack<T> *getLast() {
        return stack->getLastLink();
    }

    bool pop() {
        if (stack->getSize() != 0) {
            stack->remove();
            return true;
        } else return false;
    }

    void PopAll() {
        if (stack->getSize() != 0) {
            auto e = stack->getLastLink();
            while (e != nullptr) {
                stack->remove();
                e = stack->getLastLink();
            }
        } else std::cout << "Manager is empty!" << std::endl;
    }

    void Process() {
        elementStack<T> *e = stack->getLastLink();
        e->data();
    }

    bool checkProcess() {
        return false;
    }

    int getSize() {
        return stack->getSize();
    }

private:
    //Стэк наших функций
    Stack<T> *stack = nullptr;  //void(*)()
};

#endif //CMAKETEST_PROCESSMANAGER_H