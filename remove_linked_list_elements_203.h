//
// Created by Jing Liu on 13.01.24.
//

#ifndef PROGRAMMERCARL_CPP_REMOVE_LINKED_LIST_ELEMENTS_203_H
#define PROGRAMMERCARL_CPP_REMOVE_LINKED_LIST_ELEMENTS_203_H

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {} // constructor, invoked automatically at the time of object creation
};

// 不用虚拟头节点
class Solution_1 {
public:
    ListNode* removeElements(ListNode* head, int target) {
        // when target is head value.
        while (head != nullptr && head->val == target) { // 注意不是if，因为当链表前面几个数都是目标值时需要循环删除。
            ListNode* tmp = head;
            head = tmp->next;
            delete tmp;
        }
        // delete none head node.
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == target) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

//使用虚拟头节点
class Solution_2 {
public:
    ListNode* removeElements(ListNode* head, int target) {
        ListNode* dummyHead = new ListNode(0); // define a virtual node pointed to head
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != nullptr) {
            if (cur->next->val == target) {
                ListNode* tmp = cur->next; // 这里定义的tmp是为了以后可以释放这个内存
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

#endif //PROGRAMMERCARL_CPP_REMOVE_LINKED_LIST_ELEMENTS_203_H
