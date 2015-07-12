//
//  main.cpp
//  RemoveNthNodeFromEndOfList
//
//  Created by Fire on 15/7/12.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#include <iostream>
#include <vector>
#include "SinglyLinkedList.h"

int main(int argc, const char * argv[]) {
    
//    int i = 1;
//    ListNode a(i++);
//    ListNode b(i++);
//    ListNode c(i++);
//    
//    a.next = &b;
//    b.next = &c;
    
//    Solution s;
////    ListNode tail(-1);
////    cout << s.getTailAndSize(&a, &tail) << endl;;
////    ShowList(&a);
//
////    s.removeNthFromEnd(&a, 1);
//    s.removeNthFromEnd(&a, 2);
//    ShowList(&a);
    
    ListNode* node1;
    ListNode* node2;
    vector<ListNode*> vec;
    
    int half_len = 5;
    for (int i = 0, num = 1; i < half_len; i++) {
        
        node1 = new ListNode(num++);
        node2 = new ListNode(num++);
        
        vec.push_back(node1);
        vec.push_back(node2);
    }
    
    for (auto ite = vec.begin(); ite != --vec.end(); ite++) {
        
        auto nextIte = ite;
        nextIte++;
        
        (*ite)->next = (*nextIte);
    }
    
    auto head = *vec.begin();
    ShowList(head);
    
    Solution s;
    head = s.removeNthFromEnd(head, 1);
    ShowList(head);

    head = s.removeNthFromEnd(head, 1);
    ShowList(head);
    
    head = s.removeNthFromEnd(head, 2);
    ShowList(head);
    
    ListNode tail(-101);
    head = s.removeNthFromEnd(head, s.getTailAndSize(head, &tail) );
    ShowList(head);
    
    head = s.removeNthFromEnd(head, s.getTailAndSize(head, &tail) );
    ShowList(head);
    
    head = s.removeNthFromEnd(head, 5);
    ShowList(head);
    
    for (auto ite = vec.begin(); ite != vec.end(); ite++)
    {
        delete * ite;
    }
    
    return 0;
}
