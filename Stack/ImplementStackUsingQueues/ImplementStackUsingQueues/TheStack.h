//
//  TheStack.h
//  ImplementStackUsingQueues
//
//  Created by Fire on 15/7/12.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#ifndef ImplementStackUsingQueues_TheStack_h
#define ImplementStackUsingQueues_TheStack_h

/**
 Implement the following operations of a stack using queues.
 
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 empty() -- Return whether the stack is empty.
 
 Notes:
 
 You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

 */

#include <iostream>
#include <queue>
//#include <deque>

using namespace std;

void Show(const queue<int>& ref_queue)
{
    auto qu = ref_queue;
    while (qu.size())
    {
        cout << qu.front() << ",";
        qu.pop();
    }
    cout << "NIL" << endl;
}

// leetcode run time 0 ms

class TheStack {
public:
    
    // Push element x onto stack.
    void push(int x) {
        _queue.push(x);
    }
    
    // Removes the element on top of the stack.
    void pop() {
        if (_queue.empty()) {
            return;
        }
        
        auto originSize = _queue.size();
        
        // 最后一个元素之前的元素, 依次队尾插入
        for (int i = 0; i < originSize - 1; i++) {
            
            auto x = _queue.front();// peek
            _queue.push(x);
            _queue.pop();
        }
        
        // 原最后的元素, 现在是队首, 即栈顶
//        result = _queue.front();
//        _queue.push(result);
        _queue.pop();
        
    }
    
    // Get the top element.
    int top() {
        int result = -1;
        if (_queue.empty()) {
            return result;
        }
        
        auto originSize = _queue.size();
        // 最后一个元素之前的元素, 依次队尾插入
        for (int i = 0; i < originSize - 1; i++) {
            
            auto x = _queue.front();// peek
            _queue.push(x);
            _queue.pop();
        }
        
        // 原最后的元素, 现在是队首, 即栈顶
        result = _queue.front();
        _queue.push(result);
        _queue.pop();
        
        return result;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return _queue.empty();
    }
    
protected:
    queue<int> _queue;
};

typedef TheStack Stack;

#endif
