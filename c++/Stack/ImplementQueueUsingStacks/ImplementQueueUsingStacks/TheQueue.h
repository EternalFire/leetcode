//
//  TheQueue.h
//  ImplementQueueUsingStacks
//
//  Created by Fire on 15/7/12.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#ifndef ImplementQueueUsingStacks_TheQueue_h
#define ImplementQueueUsingStacks_TheQueue_h

/**
 Implement the following operations of a queue using stacks.
 
 push(x) -- Push element x to the back of queue.
 pop() -- Removes the element from in front of queue.
 peek() -- Get the front element.
 empty() -- Return whether the queue is empty.
 
 Notes:
 
 You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 
 class Queue {
 public:
 // Push element x to the back of queue.
 void push(int x) {
 
 }
 
 // Removes the element from in front of queue.
 void pop(void) {
 
 }
 
 // Get the front element.
 int peek(void) {
 
 }
 
 // Return whether the queue is empty.
 bool empty(void) {
 
 }
 };

 */

#include <stack>
using namespace std;

// leetcode runtime 0 ms

class TheQueue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        _stack.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        this->pop(true);
    }
    
    // Get the front element.
    int peek(void) {
        return this->pop(false);
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return _stack.empty();
    }
    
protected:
    int pop(bool isPop) {
        int result = -1;
        
        // 清空缓存栈
        while (!_tmp.empty()) {
            _tmp.pop();
        }
        
        auto len = _stack.size();
        
        // 栈弹出, 压入缓存栈
        for (int i = 0; i < len; i++) {
            auto x = _stack.top();
            _tmp.push(x);
            _stack.pop();
        }
        
        // 缓存栈的栈顶元素, 就是队首
        result = _tmp.top();
        if (isPop) {
            _tmp.pop();// 弹出队首
        }
        
        // 缓存栈 再次压回 栈中
        auto lenTmp = _tmp.size();
        for (int i = 0; i < lenTmp; i++) {
            auto x = _tmp.top();
            _tmp.pop();
            _stack.push(x);
        }
        
        return result;
    }
    
protected:
    stack<int> _stack;
    stack<int> _tmp;
};

typedef TheQueue Queue;

#endif
