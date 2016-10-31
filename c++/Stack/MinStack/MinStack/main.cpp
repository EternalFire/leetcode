//
//  main.cpp
//  MinStack
//
//  Created by Fire on 15/7/12.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#include <iostream>
#include "MinStack_Array.h"
#include "MinStack_Vector.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
//    MinStack_Array mstack;
    MinStack_Vector mstack;
    
    mstack.push(2);
    mstack.push(0);
    mstack.push(3);
    mstack.push(0);
    cout << mstack.getMin() << ",";
    mstack.pop();
    cout << mstack.getMin()<< ",";
    mstack.pop();
    cout << mstack.getMin()<< ",";
    mstack.pop();
    cout << mstack.getMin()<< ",";
    
    return 0;
}
