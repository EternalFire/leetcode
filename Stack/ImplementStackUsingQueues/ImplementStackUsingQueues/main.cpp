//
//  main.cpp
//  ImplementStackUsingQueues
//
//  Created by Fire on 15/7/12.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#include <iostream>
//#include <queue>
//#include <deque>
#include "TheStack.h"

using namespace std;

void testQueue()
{
    int i = 0;
    queue<int> Q;
    Q.push(i++);
    Q.push(i++);
    Q.push(i++);
    
    auto show = [](const queue<int>& ref_queue)
    {
        auto qu = ref_queue;
        while (qu.size())
        {
            cout << qu.front() << ",";
            qu.pop();
        }
        cout << "NIL" << endl;
    };
    
    show(Q);
    show(Q);
}

int main(int argc, const char * argv[]) {
    
    Stack s;
    for (int i = 0; i < 10; i++) {
        s.push(i);
        if (i % 2 ) {
            s.pop();
        }
        
//        if (i % 2 == 0){
//            s.pop();
//        }
    }
    
    while (!s.empty()) {
        cout << s.top() << ", ";
        s.pop();
    }
    
    cout << "\n\n===== finish ...... \n";
    return 0;
}
