// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

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

void split(Node* first, Node*& a, Node*& b) {
    if (first == nullptr) {
        return;
    }
    Node* fast = first->next;
    Node* slow = first;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    a = first;
    b = slow->next;
    slow->next = nullptr;
}

Node* sortedMergeAbs(Node* a, Node* b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }

    Node* result;

    if (std::abs(a->data) <= std::abs(b->data)) {
        result = new Node{ a->data, nullptr };
        result->next = sortedMergeAbs(a->next, b);
    }
    else {
        result = new Node{ b->data, nullptr };
        result->next = sortedMergeAbs(a, b->next);
    }

    return result;
}

void mergeSort(Node*& first) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node* a;
    Node* b;

    split(first, a, b);

    mergeSort(a);
    mergeSort(b);

    first = sortedMergeAbs(a, b);
}

void sortByAbs(Node*& first) {
    mergeSort(first);
}

void sort(Node*& first) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node* current = first;
    Node* prev;

    while (current != nullptr) {
        if (current->data < 0 && current != first) {
            prev->next = current->next;
            current->next = first;
            first = current;
            current = prev->next;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    Node* first = new Node{ -3,
                    new Node{1,
                    new Node{2,
                    new Node{-10,
                    new Node{11,
                    new Node{-7, nullptr}}}}} };
    sortByAbs(first);
    printList(first);
    sort(first);
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
