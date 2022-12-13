// task4.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

bool isSorted(Node* first) {
    while (first != nullptr) {
        if (first->next != nullptr) {
            if (first->data > first->next->data) {
                return false;
            }
        }
        first = first->next;
    }

    return true;
}

Node* findMiddleElementInList(Node* first, Node* end) {
    if (first == nullptr) {
        return first;
    }

    Node* slow = first;
    Node* fast = first->next;

    while (fast != nullptr && fast != end) {
        fast = fast->next;
        if (fast != nullptr && fast != end) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

Node* binarySearch(Node* first, int key, Node* last = nullptr) {
    if (first == nullptr) {
        return first;
    }

    Node* middle = findMiddleElementInList(first, last);
    if (key == middle->data) {
        return middle;
    }
    else if (key < middle->data) {
        return binarySearch(first, key, middle);
    }
    else {
        return binarySearch(middle->next, key);
    }
}

int main() {
    Node* first = new Node{ 1,
                    new Node{2,
                    new Node{3,
                    new Node{4,
                    new Node{5, nullptr}}}} };

    Node* found = binarySearch(first, 4);
    std::cout << found->next->data << std::endl;

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
