//
//  EvalRPN.h
//  EvalRPN
//
//  Created by Fire on 15/7/14.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#ifndef EvalRPN_EvalRPN_h
#define EvalRPN_EvalRPN_h

/**
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 
 Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 
 Some examples:
 
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool isOperator(const string& str){
    bool result = false;
    
    if (str.compare("+") == 0 ||
        str.compare("-") == 0 ||
        str.compare("*") == 0 ||
        str.compare("/") == 0 ||
        str.compare("(") == 0 ||
        str.compare(")") == 0)
    {
        result = true;
    }
    
    return result;
}

template <typename T>
T calcByOperator(const string& str, const T& num1, const T& num2) {
    
    T result = 0;
    if (str.compare("+") == 0) {
        result = num1 + num2;
    }
    if (str.compare("-") == 0) {
        result = num1 - num2;
    }
    if (str.compare("*") == 0) {
        result = num1 * num2;
    }
    if (str.compare("/") == 0) {
        result = num1 / num2;
    }
    //    cout << num1 << " " << str << " " << num2 << " = " << result << endl;
    return result;
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        auto& expression = tokens;
        int result = 0;
        if (expression.empty()) {
            return result;
        }
        stack<int> sk; //存放运算结果
        
        // 从左至右遍历后缀表达式
        for (auto ite = expression.begin(); ite != expression.end(); ite++) {
            
            // 如果是符号, 则弹出两个数字进行运算, 运算结果再进栈
            if (isOperator(*ite)) {
                auto numA = sk.top(); sk.pop();
                auto numB = sk.top(); sk.pop();
                // 注意弹出的顺序
//                auto x = calcByOperator<int>(*ite, numA, numB);
                auto x = calcByOperator<int>(*ite, numB, numA);
                sk.push(x);
            }
            else{
                // 如果是数字, 则进栈
                sk.push(atoi(ite->c_str()));
            }
        }
        result = sk.top();
        
        return result;
    }
};

#endif
