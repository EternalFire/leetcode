//
//  SinglyLinkedList.h
//  RemoveNthNodeFromEndOfList
//
//  Created by Fire on 15/7/12.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#ifndef RemoveNthNodeFromEndOfList_SinglyLinkedList_h
#define RemoveNthNodeFromEndOfList_SinglyLinkedList_h

/**
 Given a linked list, remove the nth node from the end of list and return its head.
 
 For example,
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 
 Note:
 Given n will always be valid.
 Try to do this in one pass.
 

 Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 class Solution {
 public:
 ListNode* removeNthFromEnd(ListNode* head, int n) {
 
 }
 };
 
 */

#include <iostream>

using namespace std;

// leetcode run time 4 ms

// 单链表结点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void ShowList(ListNode* head)
{
    auto node = head;
    while (node) {
        cout << node->val << ", ";
        node = node->next;
    }
    cout << "NIL" << endl;
}

class Solution {
public:
    // 移除 倒数 第n个结点, 返回 头结点
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode tail(-1);
        int size = this->getTailAndSize(head, &tail);
        
        int len = size - n; // 递进次数
        if (len == 0) {
            return head->next;
        }
        
        auto node = head;
        for (int i = 1; i < len; i++)
        {
            node = node->next;
        }
        
        auto prev_node = node; // 删除结点的上一个结点
        auto next_node = node->next->next; // 删除结点的下一个结点
        prev_node->next = next_node;
        
        return head;
    }
    
//protected:
    // 返回末结点, 链表大小
    int getTailAndSize(ListNode* head, ListNode* tail)
    {
        int size = 0;
        ListNode* node = nullptr;
        node = head;
        
        // 遍历结点, 直到末结点
        while (node->next)
//        while(node)
        {
            node = node->next;
            size++;
        }
        *tail = *node;
        size++;
        
        return size;
    }
};

#endif
