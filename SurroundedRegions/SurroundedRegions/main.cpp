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

// 可以只判断边界连通的O元素, 而不管边界内的O元素

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "StringVectorUtil.h"
#include "Surround.h"
#include "Header.h"

using namespace std;
using namespace StringVectorUtil;

double Start() {
    time_t timep;
//    tm *p;
    time(&timep);
////    p = localtime(&timep);
    cout << ctime(&timep) << endl;
    return (double)clock() / CLOCKS_PER_SEC * 1000;
}

double End() {
    time_t timep;
    time(&timep);
    cout << ctime(&timep) << endl;
    return (double)clock() / CLOCKS_PER_SEC * 1000;
}

int main(int argc, const char * argv[]) {
    
    string str =
"\
X X X X O X X\n\
X O O X X O X\n\
X X O X O X O\n\
X O X X X X X\n\
X O X X O O X\n\
X O O X O X X\n\
X X X O O X O\n\
";
//    auto array = String_TwoDimensionalArray(str, " ", "\n");
//    cout << TwoDimensionalArray_String(array, " ", "\n");
//    
//    vector<vector<char>> board;
//    board = VVString_VVChar(array);
    
    //begin
    vector<vector<char>> board;
    int rowNum = sizeof(InputData) / sizeof(InputData[0]);
    int colNum = 0;
    
    for (int i = 0; i < sizeof(InputData[0]) / sizeof(char); i++ )
    {
        if (InputData[0][i]) {
            colNum++;
        }
        else {
            break;
        }
    }
    str = "";
    for (int i = 0; i < rowNum; i++) {
        vector<char> rowData;
        
        for (int j = 0; j < colNum; j++) {
            rowData.push_back(InputData[i][j]);
            cout << InputData[i][j] << " ";
        }
        
        board.push_back(rowData);
        cout << "\n";
    }
    //end
    
    auto t1 = Start();
    Solution s;
    s.solve(board);
    
//    for (int i = 0; i < 10000* 10000; i++) {
//        i;
//    }
    auto t2 = End();
    cout << "delta : " << t2 - t1 << "ms"<< endl;
    
    vector<vector<string>> newArray;
    newArray = VVChar_VVString(board);
    cout << TwoDimensionalArray_String(newArray, " ", "\n");
    cout << "Finish main().........." << endl;
    cout << "delta : " << t2 - t1 << "ms"<< endl;
    
    return 0;
}
