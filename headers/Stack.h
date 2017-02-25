#ifndef CMAKETEST_STACK_H
#define CMAKETEST_STACK_H

#include <iostream>

template<typename T>
class elementStack {
public:
    elementStack() {
        std::cout << "New elem of Stack Created!" << std::endl;
    }

    ~elementStack() {
        std::cout << "Elem of Stack destroyed!" << std::endl;
    }

    T data;
    elementStack<T> *next;
};

template<typename T>
class Stack {
private:
    elementStack<T> *first = nullptr; //head of stack
    int size = 0;
public:
    Stack() {
        std::cout << "Stack created!" << std::endl;
    }

    ~Stack() {
        if (size != 0) {
            elementStack<T> *tmp = nullptr;
            while (first != nullptr) {
                tmp = first->next;
                delete first;
                first = tmp;
                --size;
            }
            std::cout << "Stack destroyed!" << std::endl;
        } else std::cout << "Stack was empty. Removed nothing" << std::endl;
    }

    /*
        Добавляет новый элемент в стек
        (Adds new element in stack)
    */
    void push(const T data) {
        elementStack<T> *newElem = new elementStack<T>();
        if (size == 0) newElem->next = nullptr;
        else newElem->next = first;
        first = newElem;
        newElem->data = data;
        ++size;
    }

    /*
        Возвращает указатель на последний добавленный элемент в стеке
        (return pointer for last added element in stack)
    */
    elementStack<T> *getLastLink() {
        return first;
    }

    /*
        Удаляет последний добавленный элемент в stack
        (Removes last element in stack)
    */
    void remove() {
        elementStack<T> *e;
        e = first->next;
        delete first;
        first = e;
        --size;
    }

    /*
        return size of stack
    */
    int getSize() {
        return size;
    }

    void viewSize() {
        std::cout << "Size = " << size << std::endl;
    }
};

#endif //CMAKETEST_STACK_H
