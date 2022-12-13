// task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
void keepProducts(Node<T>* first) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node<T>* l1 = first;
    Node<T>* l2 = first->next;
    Node<T>* current = first->next->next;

    while (current != nullptr) {
        if (current->data % l1->data != 0 || current->data % l2->data != 0) {
            //current->data != l1->data + l2->data - makeFib
            Node<T>* toDelete = current;
            l2->next = current->next;
            delete toDelete;
            current = l2->next;
        }
        else {
            l1 = l2;
            l2 = current;
            current = current->next;
        }
    }
}

int main() {
    Node<int>* l1 = new Node<int>{ 2,
                         new Node<int>{3,
                             new Node<int>{3,
                                 new Node<int>{12,
                                      new Node<int>{72,
                                          new Node<int>{36,nullptr}}}}} };

    print(l1);
    keepProducts(l1);
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
