#include <iostream>
#include "Array1D.hpp"

// TODO: add array 2d realization



int main() {
    Array1D<int> arr(10);
    for (int i = 0; i < arr.getSize(); i++) {
        arr[i] = i;
    }
    arr[0] = 1;
    arr.insert(10);
    arr.insert(11);
    arr.remove(1);
    for (size_t i = 0; i < arr.getSize(); i++) {
        std::cout << arr[i] << std::endl;
    }
}


