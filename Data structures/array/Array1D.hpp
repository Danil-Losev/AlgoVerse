//
// Created by Admin on 21.05.2025.
//

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>

template<typename ValueType>
class Array1D {
private:
    ValueType *data;
    size_t size;

public:
    Array1D() : data(nullptr), size(0) {
    }

    Array1D(size_t size) : size(size) {
        data = new ValueType[size];
    }

    Array1D(const Array1D &other) : size(other.size) {
        data = new ValueType[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~Array1D() {
        delete[] data;
    }

    bool insert(ValueType value);

    ValueType get(size_t index) const;

    bool remove(size_t index);

    size_t getSize() const {
        return size;
    }

    ValueType &operator[](size_t index);
};

template<typename ValueType>
bool Array1D<ValueType>::insert(ValueType value) {
    try {
        ValueType *newArray = new ValueType[size + 1];
        for (size_t i = 0; i < size; ++i) {
            newArray[i] = data[i];
        }
        newArray[size] = value;
        delete[] data;
        data = newArray;
        size++;
        return true;
    } catch (...) {
        return false;
    }
}

template<typename ValueType>
ValueType Array1D<ValueType>::get(size_t index) const {
    return data[index];
}

template<typename ValueType>
bool Array1D<ValueType>::remove(size_t index) {
    try {
        ValueType *newArray = new ValueType[size - 1];
        size_t elements = 0;
        for (size_t i = 0; i < size; ++i) {
            if (i != index) {
                newArray[elements] = data[i];
                elements++;
            }
        }
        delete[] data;
        data = newArray;
        size--;
        return true;
    } catch (...) {
        return false;
    }
}

template<typename ValueType>
ValueType &Array1D<ValueType>::operator[](size_t index) {
    if (index >= size || index < 0) { throw std::out_of_range("Index out of range"); }
    return data[index];
}

#endif //ARRAY_HPP
