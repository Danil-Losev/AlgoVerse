#include <iostream>
#include <windows.h>
#include "LinkedList.hpp"

void test(int size);

int main() {
    LinkedList<int> list;
    list.addBefore(0, 1000);
    list.addAfter(0, 100);
    for (size_t i = 0; i < 10; i++) {
        list.addBack(i);
    }
    list.addFront(-1);
    for (size_t i = 0; i < list.getSize(); i++) {
        std::cout << list[i] << ' ';
    }
    std::cout << std::endl;
    list.removeAt(0);
    list.removeFront();
    list.removeBack();
    list.removeAt(list.getSize() / 2);
    for (size_t i = 0; i < list.getSize(); i++) {
        std::cout << list[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
