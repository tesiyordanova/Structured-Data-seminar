// task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <class T>
struct Node {
    T data;
    Node* next;
};

template <class T>
void print(Node<T>* first) {
    if (first == nullptr) {
        std::cout << "nullptr\n";
        return;
    }

    std::cout << first->data << " ";
    print(first->next);
}

template <class T>
Node<T>* copyList(Node<T>* first) {
    if (first == nullptr) {
        return first;
    }

    Node<T>* result = new Node<T>{ first->data, nullptr };
    Node<T>* current = result;
    first = first->next;

    while (first != nullptr) {
        current->next = new Node<T>{ first->data, nullptr };
        first = first->next;
        current = current->next;
    }

    return result;
}

template <class T>
void reverse(Node<T>*& first) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node<T>* prev = nullptr;
    Node<T>* current = first;
    Node<T>* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    first = prev;
}

template <class T>
void mirror(Node<T>* first) {
    if (first == nullptr) {
        return;
    }

    Node<T>* copyFirst = copyList(first);
    reverse(copyFirst);

    while (first->next != nullptr) {
        first = first->next;
    }

    first->next = copyFirst;
}

template <class T>
void mirror2(Node<T>*& first) {
    if (first == nullptr) {
        return;
    }

    reverse(first);

    Node<T>* current = first;

    while (current != nullptr) {
        first = new Node<T>{ current->data, first };
        current = current->next;
    }
}

int main() {
    Node<int>* l1 = new Node<int>{ 1,
                         new Node<int>{3,
                             new Node<int>{5,nullptr}} };

    print(l1);
    mirror2(l1);
    print(l1);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
