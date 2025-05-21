#include <iostream>
#include <windows.h>
#include "LinkedList.hpp"

void test(int size);

int main() {
    LinkedList<int> list;
    for (int i = 1; i <= 10; i++) {
        list.addBack(i);
    }
    list.addFront(0);
    for (int i = 0; i < list.getSize(); i++) {
        std::cout << list[i] << ' ';
    }
    list.removeBack();
    list.removeFront();

    std::cout << '\n';

    for (int i = 0; i < list.getSize(); i++) {
        std::cout << list[i] << ' ';
    }

    std::cin.get();
    test(100000);
    std::cin.get();

    return 0;
}

void test(const int size) {
    LinkedList<int> list;
    for (int i = 0; i < size; i++) {
        list.addBack(i);
    }
    for (int i = 0; i < list.getSize(); i++) {
        std::cout << list[i] << ' ';
    }
    std::cin.get();
}