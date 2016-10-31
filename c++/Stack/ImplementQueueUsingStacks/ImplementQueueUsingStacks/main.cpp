//
//  main.cpp
//  ImplementQueueUsingStacks
//
//  Created by Fire on 15/7/12.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#include <iostream>
//#include <stack>
#include "TheQueue.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Queue q;
    
    for (int i = 0; i < 10; i++) {
        
        q.push(i);
        
        if (i % 2) {
            q.pop();
        }
    }
    
    while (!q.empty()) {
        cout << q.peek() << ",";
        q.pop();
    }
    
    return 0;
}
