//
//  main.cpp
//  ReverseLinkedList
//
//  Created by Fire on 15/7/13.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#include <iostream>
#include "ReverseLinkedList.h"

using namespace std;

void ShowListNode(ListNode* head)
{
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    cout << endl;
}

int main(int argc, const char * argv[]) {

    ListNode a(10);
    ListNode b(11);
    ListNode c(12);
    ListNode d(13);
    
    a.next = &b; b.next = &c; c.next = &d;
    ShowListNode(&a);
    
    Solution s;
    ListNode* result;
//    result = s.reverseList(&a);
//    result = s.reverseList_stack(&a);
    result = s.reverseList_exchange(&a);
    
    ShowListNode(result);
    
    
    return 0;
}
