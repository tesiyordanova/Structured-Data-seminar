﻿// update_linkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <initializer_list>
#include <vector>
#include <cassert>

using namespace std;

#include <stdexcept>

struct Node {
    int val;
    Node* next;
    Node* prev; // TODO: implement double linked list
    Node() : val(0), next(nullptr) {}

    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        while (this->head != nullptr) {
            Node* toDelete = this->head;
            this->head = this->head->next;
            delete toDelete;
        }
    }

    void insertFirst(int value) {

        Node* node = new Node(value, this->head);
        this->head = node;
        if (this->tail == nullptr) {
            this->tail = node;
        }
    }

    void insertLast(int value) {
        Node* node = new Node(value, nullptr);
        if (this->tail == nullptr) {
            this->head = node;
            this->tail = node;
        }
        else {
            this->tail->next = node;
            this->tail = node;
        }
    }

    void insertAfter(int value, Node* iterator) {
        // insert after
        if (iterator == nullptr) {
            // do nothing
            return;
        }

        Node* node = new Node(value);
        node->next = iterator->next;
        iterator->next = node;


        if (iterator->next == nullptr) {
            this->tail = node;
        }
    }

    int removeFirst() {
        if (this->head == nullptr) {
            throw std::invalid_argument("Removing element from an empty list.");
        }

        Node* tmp = this->head;
        this->head = this->head->next;
        int value = tmp->val;
        delete tmp;
        return value;
    }


    int removeLast() {
        if (this->head == nullptr) {
            throw std::runtime_error("deleting from Empty list");
        }
        if (this->head != this->tail) {
            Node* prev = this->head;
            while (prev->next != this->tail) {
                prev = prev->next;
            }
            prev->next = nullptr;
            int value = this->tail->val;
            delete this->tail;
            this->tail = prev;
        }
        else {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
        }

    }


    int removeAfter(Node* iterator) {
        // we assume iterator is part of the list
        if (this->head == nullptr) {
            throw std::runtime_error("deleting from Empty list ");
        }
        if (iterator == nullptr or iterator->next == nullptr) {
            throw std::runtime_error("No element found to remove ");
        }
        Node* toDelete = iterator->next;
        iterator->next = toDelete->next;
        if (this->tail == toDelete) {
            this->tail = iterator;
        }
        int value = toDelete->val;
        delete toDelete;
        return value;
    }

    std::vector<int> to_vector() {
        Node* current = this->head;
        std::vector<int> v;
        while (current != nullptr) {
            v.push_back(current->val);
            current = current->next;
        }
        return v;
    }

    Node* get_node_at_index(int index) {
        Node* current = this->head;
        while (current != nullptr && index > 0) {
            index--;
            current = current->next;
        }
        return current;
    }
};


LinkedList create_test_list(std::initializer_list<int> list)
{
    LinkedList test_list;
    for (auto elem : list)
    {
        test_list.insertFirst(elem);
    }
    return test_list;
}

void test_insertFirst() {
    std::cout << "test_insertFirst\n";
    LinkedList test;
    test.insertFirst(12);
    assert(std::vector<int>({ 12 }) == test.to_vector());

    test.insertFirst(14);
    assert(std::vector<int>({ 14, 12 }) == test.to_vector());
}

void test_insertLast() {
    std::cout << "test_insertLast\n";
    LinkedList test;
    test.insertLast(12);
    assert(std::vector<int>({ 12 }) == test.to_vector());

    test.insertLast(14);
    assert(std::vector<int>({ 12, 14 }) == test.to_vector());
}

void test_insertAfter() {
    std::cout << "test_insertAfter\n";
    LinkedList test;
    test.insertAfter(10, nullptr);
    assert(std::vector<int>({}) == test.to_vector());


    test.insertLast(12);
    test.insertAfter(10, test.get_node_at_index(0));
    assert(std::vector<int>({ 12, 10 }) == test.to_vector());

    test.insertAfter(14, test.get_node_at_index(0));
    assert(std::vector<int>({ 12, 14, 10 }) == test.to_vector());
}

void test_removeFirst() {
    // TODO
}


void test_removeLast() {
    // TODO
}

int main()
{
    test_insertFirst();
    test_insertLast();
    test_insertAfter();

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
