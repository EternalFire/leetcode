//
//  main.cpp
//  EvalRPN
//
//  Created by Fire on 15/7/14.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#include <iostream>
#include "EvalRPN.h"

vector<string> getExpressionWithStr(string str){
    vector<string> result;
    if (str.empty()) {
        return result;
    }
    
    // 分隔","
    const char* field = ",";
    while (str.find(field) != string::npos) {
        
        auto pos = str.find(field);
        auto fieldStr = str.substr(0, pos);
        str = str.substr(pos + strlen(field));
        result.push_back(fieldStr);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    vector<string> expression;
    expression = getExpressionWithStr("9,3,1,-,3,*,+,10,2,/,+,");
    Solution s;
    int result;
    result = s.evalRPN(expression);
    cout << result << endl;
    return 0;
}
