//
//  MinStack.h
//  MinStack
//
//  Created by Fire on 15/7/12.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#ifndef __MinStack__MinStack__
#define __MinStack__MinStack__

/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

class MinStack {
public:
    void push(int x) {
        
    }
    
    void pop() {
        
    }
    
    int top() {
        
    }
    
    int getMin() {
        
    }
};
 
 Hints:
 
 Consider space-time tradeoff. How would you keep track of the minimums using extra space?
 Make sure to consider duplicate elements.
 
 O(n) runtime, O(n) space – Extra stack:
 
 Use an extra stack to keep track of the current minimum value. During the push operation we choose the new element or the current minimum, whichever that is smaller to push onto the min stack.
 O(n) runtime, O(n) space – Minor space optimization:
 
 If a new element is larger than the current minimum, we do not need to push it on to the min stack. When we perform the pop operation, check if the popped element is the same as the current minimum. If it is, pop it off the min stack too.
*/

#include "string"

#define ARRAY_LEN 16384

// leetcode run time 284ms
class MinStack_Array {
public:
    MinStack_Array(){
        _top = -1;
        _size = sizeof(_array) / sizeof(*_array);
        memset(_array, 0, _size);
    }
    
    void push(int x) {
        
        if (_top == _size - 1){
            return;
        }
        
        _top++;
        _array[_top] = x;
    }
    
    void pop() {
        if (_top == -1) {
            return;
        }
        
        _array[_top] = 0;
        _top--;
    }
    
    int top() {
        return _array[_top];
    }
    
    int getMin() {
        int result = 0;
        
        if (_top != -1) {
            result = _array[0];
        }
        
        for (int i = 1; i < _top + 1; i++) {
            if (result > _array[i]) {
                result = _array[i];
            }
        }
        
        return result;
    }
    
protected:
    int _array[ARRAY_LEN];
    int _top;
    int _size;
};


#endif /* defined(__MinStack__MinStack__) */
