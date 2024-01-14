//
// Created by Jing Liu on 14.01.24.
//

#ifndef PROGRAMMERCARL_CPP_REVERSE_LINKED_LIST_206_H
#define PROGRAMMERCARL_CPP_REVERSE_LINKED_LIST_206_H

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 双指针法
class Solution_1 {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // define a temporary pointer to store cur->next.
        ListNode* prev = nullptr; // to be the last node of the linked list
        ListNode* cur = head;
        while (cur) {
            temp = cur->next;
            cur->next = prev; // flip direction
            prev = cur; // update prev and cur pointer
            cur = temp;
        }
        return prev;
    }
};

// 递归法
class Solution_2 {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode* reverse(ListNode* prev, ListNode* cur) {
        if (cur == nullptr) return prev;
        ListNode* temp = cur->next;
        cur->next = prev;
        return reverse(cur, temp); // 通过函数赋值来更新 prev 和 cur 指针。
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head); // 和双指针法对比，在这里做的初始化。
    }
};

#endif //PROGRAMMERCARL_CPP_REVERSE_LINKED_LIST_206_H
