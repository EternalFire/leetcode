//
//  main.cpp
//  SurroundedRegions
//
//  Created by Fire on 15/7/20.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

/**
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 
 A region is captured by flipping all 'O's into 'X's in that surrounded region.
 
 For example,
 
 X X X X
 X O O X
 X X O X
 X O X X
 
 After running your function, the board should be:
 
 X X X X
 X X X X
 X X X X
 X O X X

 --------------------------------------
 
 class Solution {
 public:
 void solve(vector<vector<char>>& board) {
 
 }
 };
 
 */
#include <iostream>
#include <string>
#include <vector>

#include "StringVectorUtil.h"
#include "Surround.h"

using namespace std;
using namespace StringVectorUtil;

int main(int argc, const char * argv[]) {
    
    string str =
"\
X X X X O X X\n\
X O O X X O X\n\
X X O X O X O\n\
X O X X X X X\n\
X O X X O O X\n\
X O O X O X X\n\
X X X O X X O\n\
";
    
//"\
//a b c d\n\
//X O O X\n\
//X X O X\n\
//X O X X\n\
//";
    auto array = String_TwoDimensionalArray(str, " ", "\n");
    cout << TwoDimensionalArray_String(array, " ", "\n");
    
    vector<vector<char>> board;
    board = VVString_VVChar(array);

    Solution s;
    s.solve(board);
    
    vector<vector<string>> newArray;
    newArray = VVChar_VVString(board);
    cout << TwoDimensionalArray_String(newArray, " ", "\n");
    
    return 0;
}
