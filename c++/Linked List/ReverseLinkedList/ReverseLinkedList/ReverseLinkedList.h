//
//  ReverseLinkedList.h
//  ReverseLinkedList
//
//  Created by Fire on 15/7/13.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#ifndef ReverseLinkedList_ReverseLinkedList_h
#define ReverseLinkedList_ReverseLinkedList_h

/**
 Reverse a singly linked list.
 
 Hint:
 
 A linked list can be reversed either iteratively or recursively. Could you implement both?

 Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
    }
};
 */

/**
 * Definition for singly-linked list.
 */

#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    // leetcode runtime 68 ms
    ListNode* reverseList(ListNode* head) {
        
        if (!head) {
            return nullptr;
        }
        
        ListNode* newHead = nullptr;
        ListNode* last = nullptr;
        ListNode* tmp = nullptr;
        ListNode* node = head;
        int len = 0;
        
        // 遍历链表
        while (node->next) {
            last = node;
            node = node->next;
            len++;
        }
        newHead = node; // 最后一个元素
        len++;
        
        if (len == 1) {
            return head;
        }
        
        if (last) {
            last->next = nullptr;// 倒数第二个元素
        }
        
        node = head;
        tmp = newHead;
        for (int i = 0; i < len - 1; i++) {
            
            // 再次遍历原链表
            while (node->next) {
                last = node;
                node = node->next;
            }
            
//            cout << node->val << endl;
            
            last->next = nullptr;
            tmp->next = node;
            tmp = tmp->next;
            node = head;
        }
        
        return newHead;
    }
    
    // Runtime: 12 ms
    ListNode* reverseList_stack(ListNode* head) {
        
        // 如果是空链表或只有一个元素的链表, 直接返回;
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* newHead = nullptr;
        ListNode* tmp;
        
        while (head) {
            _sk.push(head);
            head = head->next;
        }
        
        newHead = _sk.top(); // 原链表最后元素
        _sk.pop();
        tmp = newHead;
        while (_sk.size()) {
            tmp->next = _sk.top();
            tmp = tmp->next;
            _sk.pop();
        }
        tmp->next = nullptr; // 最后
        
        return newHead;
    }
    
    // Runtime: 8 ms
    ListNode* reverseList_exchange(ListNode* head){
        
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* newHead = NULL;
        ListNode* h = NULL, * p = NULL; // h : 当前头结点, p : 当前结点(需要交换移动)

        h = head;
        p = head->next;
        while (p) {
            
            // 交换
            ListNode* tmp = p->next;
//            head->next = tmp;
            p->next = h;
            h = p; // 新的头结点
            p = tmp; // 判断下一个结点
        }
        head->next = NULL;
        newHead = h;
        
        return newHead;
    }
    
protected:
    stack<ListNode*> _sk;
};

#endif
