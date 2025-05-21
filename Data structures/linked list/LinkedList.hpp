//
// Created by Admin on 21.05.2025.
//

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <stdexcept>

template<typename ListType>
class Node {
public:
    ListType value;
    Node *next;

    Node(ListType data) : value(data), next(nullptr) {}
    Node() : value(ListType()), next(nullptr) {}
    Node(const Node &node) : value(node.value), next(nullptr) {}
    ~Node() = default;
};


template<typename ListType>
class LinkedList {
private:
    Node<ListType> *head;
    size_t size;

public:
    LinkedList() : head(nullptr), size(0) {}
    ~LinkedList();


    void addBack(ListType data); // O(n)
    void addFront(ListType data); // O(1)

    ListType removeBack(); // O(n)
    ListType removeFront(); // O(1)

    ListType &operator[](size_t index); // O(n)

    size_t getSize() const { return size; }
};

template<typename ListType>
LinkedList<ListType>::~LinkedList() {
    Node<ListType> *current = head;
    while (current != nullptr) {
        Node<ListType> *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

template<typename ListType>
void LinkedList<ListType>::addBack(ListType data) {
    Node<ListType> *newNode = new Node<ListType>(data);
    if (head == nullptr) {
        head = newNode;
        size++;
    } else {
        Node<ListType> *currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
        size++;
    }
}
template<typename ListType>
void LinkedList<ListType>::addFront(ListType data) {
    Node<ListType> *newNode = new Node<ListType>(data);
    newNode->next = head;
    head = newNode;
    size++;
}
template<typename ListType>
ListType LinkedList<ListType>::removeBack() {
    if (head == nullptr) {
        throw std::out_of_range("List is empty");
    }
    Node<ListType> *currentNode = head;
    Node<ListType> *previousNode = nullptr;
    while (currentNode->next != nullptr) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    ListType value = currentNode->value;
    delete currentNode;
    previousNode->next = nullptr;
    size--;
    return value;
}
template<typename ListType>
ListType LinkedList<ListType>::removeFront() {
    if (head == nullptr) {
        throw std::out_of_range("List is empty");
    }
    Node<ListType> *currentNode = head;
    head = head->next;
    ListType value = currentNode->value;
    delete currentNode;
    size--;
    return value;
}

template<typename ListType>
ListType &LinkedList<ListType>::operator[](const size_t index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("index out of range");
    Node<ListType> *currentNode = head;
    for (size_t i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->value;
}


#endif // LINKEDLIST_HPP
