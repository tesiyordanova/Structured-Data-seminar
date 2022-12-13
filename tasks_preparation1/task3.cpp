// task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

bool hasCycle(Node* first) { //endless loop
    if (first == nullptr) {
        return false;
    }

    Node* slow = first;
    Node* fast = first->next;

    while (fast != nullptr) {
        if (fast == slow) {
            return true;
        }
        fast = fast->next;
        if (fast != nullptr) {
            if (fast == slow) {
                return true;
            }
            fast = fast->next;
            slow = slow->next;
        }
        if (slow == nullptr) {
            return false;
        }
    }

    return fast == slow;
}

int main() {
    Node* first = new Node{ 1, new Node{2, nullptr} };
    Node* repeat = new Node{ 3, new Node{4, nullptr} };
    first->next->next = repeat;
    repeat->next->next = new Node{ 5, repeat };

    std::cout << hasCycle(first) << std::endl;

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
