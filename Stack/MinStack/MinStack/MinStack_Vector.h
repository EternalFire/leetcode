//
//  MinStackNew.h
//  MinStack
//
//  Created by Fire on 15/7/12.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#ifndef MinStack_MinStackNew_h
#define MinStack_MinStackNew_h

#include <vector>

using namespace std;

// leetcode run time 32ms
class MinStack_Vector {
public:
    MinStack_Vector(){//:_top(-1){
        int size = 20000;
        _stack.reserve(size);
        _minStack.reserve(size);
    }
    
    void push(int x) {
        
        // 出现过的最小值
        if ( _minStack.empty() || *_minStack.rbegin() >= x) {
            _minStack.push_back(x);
        }
        
        _stack.push_back(x);
    }
    
    void pop() {
        const int& x = *_stack.rbegin();
        if (x == *_minStack.rbegin()) {
            _minStack.pop_back();
        }
        _stack.pop_back();
    }
    
    int top() {
        return *_stack.rbegin();
    }
    
    int getMin() {
        return *_minStack.rbegin();
    }
    
protected:
//    int _top;
    vector<int> _stack;
    vector<int> _minStack; // 记录栈中存在过的最小值
};

#endif
