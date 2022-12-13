// is_palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {

public:
    bool isPalindrome(ListNode* head) {
        auto copy = copy_list(head); // or copy_list_recursive
        copy = reverse(copy);
        auto is_palindrom = compare(copy, head);
        delete_list(copy);
        return is_palindrom;

    }

private:

    ListNode* copy_list_recursive(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* new_node = new ListNode(head->val);
        new_node->next = copy_list_recursive(head->next);
        return new_node;
    }

    ListNode* copy_list(ListNode* head) {
        ListNode start(0);
        ListNode* prev = &start;
        while (head != nullptr) {
            auto new_node = new ListNode(head->val);
            prev->next = new_node;
            prev = new_node;
            head = head->next;
        }
        return start.next;
    }

    void delete_list(ListNode* head) {
        while (head != nullptr) {
            auto prev = head;
            head = head->next;
            delete prev;
        }
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }


    bool compare(ListNode* lhs, ListNode* rhs) {
        while (lhs != nullptr && rhs != nullptr && lhs->val == rhs->val) {
            lhs = lhs->next;
            rhs = rhs->next;
        }
        return lhs == nullptr && rhs == nullptr;
    }

};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
