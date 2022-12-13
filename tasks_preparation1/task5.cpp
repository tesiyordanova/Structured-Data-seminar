// task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    int data;
    Node* next;
};

void printList(Node* first) {
    while (first) {
        std::cout << first->data << " -> ";
        first = first->next;
    }
    std::cout << "nullptr\n";
}

void concatLists(Node*& first, Node* second) {
    if (first == nullptr) {
        first = second;
        return;
    }
    if (second == nullptr) {
        return;
    }

    Node* currentFirst = first;
    while (currentFirst->next != nullptr) {
        currentFirst = currentFirst->next;
    }

    Node* currentSecond = second;
    while (currentSecond != nullptr) {
        Node* toDelete = currentSecond;
        currentFirst->next = new Node{ currentSecond->data, nullptr };
        currentFirst = currentFirst->next;
        currentSecond = currentSecond->next;
        delete toDelete;
    }
}

void groupElements(Node*& first) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node* current = first->next->next;
    Node* evens = new Node{ first->next->data, nullptr };
    Node* currentEvens = evens;
    Node* odds = new Node{ first->data, nullptr };
    Node* currentOdds = odds;
    int counter = 1;

    while (current != nullptr) {
        if (counter % 2 == 0) {
            currentEvens->next = new Node{ current->data, nullptr };
            currentEvens = currentEvens->next;
        }
        else {
            currentOdds->next = new Node{ current->data, nullptr };
            currentOdds = currentOdds->next;
        }
        current = current->next;
        ++counter;
    }

    concatLists(odds, evens);
    first = odds;
}

int main() {
    Node* first = new Node{ 1,
                    new Node{2,
                    new Node{3, nullptr}} };

    Node* second = new Node{ 4,
                    new Node{5,
                    new Node{6, nullptr}} };

    concatLists(first, second);
    printList(first);

    groupElements(first);
    printList(first);

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
