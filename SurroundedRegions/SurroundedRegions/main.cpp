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

using namespace std;
using namespace StringVectorUtil;

class Solution {
protected:
    char _O;
    char _X;
    int _lenX; // 二维数组x轴大小
    int _lenY; // 二维数组y轴大小
    
    enum Direction{
        kUp = 0,
        kDown,
        kLeft,
        kRight
    };
    struct Element{
        int _x, _y;
        char _value;
        char _connected[4]; // 上下左右的连通标识, 1: 连通
        
        Element(){
            memset(this, 0, sizeof(Element));
        }
        
        bool operator!=(const Element & other) {
//            return memcmp(this, &other, sizeof(Element) - sizeof(_connected) / sizeof(char)) != 0;
            if (_x == other._x && _y == other._y && _value == other._value) {
                return false;
            }
            else {
                return true;
            }
        }
        
        bool operator==(const Element & other) {
//            return memcmp(this, &other, sizeof(Element) - sizeof(_connected) / sizeof(char)) == 0;
            if (_x == other._x && _y == other._y && _value == other._value) {
                return true;
            }
            else {
                return false;
            }
        }
    };
    Element Element_None;
//    vector<vector<char>> _array; // 原始数据
    vector<Element> _connected; // 连通的O元素
    
public:
    Solution():_lenX(0), _lenY(0), _O('O'), _X('X'){}
    
    void solve(vector<vector<char>>& board) {

        if (isValid(board) == false) {
            return;
        }
        
        // 每行每列从第二个元素开始判断(index = 1)
        // 1. 非边界元素 判断 它的上下左右元素 是否是 _O
        // 2. 连通的元素 判断 不连通的一侧 是否是 _X
        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; x < board[y].size(); x++) {
                check(board, x, y);
            }
        }
        
        cout << "finish \n";
    }
    
    // 二维数组大小在 x, y 方向 都大于等于3时, 才能实现包围
    bool isValid(const vector<vector<char>>& board) {
        int valid_len = 3;
        
        if (board.size() >= valid_len) {
            
            for (auto dataRow : board) {
                
                if (dataRow.size() < valid_len) {
                    return false;
                }
            }
            
            init(board);
            
            return true;
        }
        else {
            return false;
        }
    }
    
    void init(const vector<vector<char>>& board) {
        _lenX = (int)board.begin()->size();
        _lenY = (int)board.size();
    }
    
    // 返回元素(e), 在某方向相邻的元素
    Element getElementByDirection(vector<vector<char>>& board, const Element& e, Direction d) {
        
        Element result;
        
        switch (d) {
            case Direction::kUp :
            {
                if (e._y <= 0) {
                    break;
                }
                result._x = e._x;
                result._y = e._y - 1;
                result._value = board[result._y][result._x];
//                cout << "checking up--------" << endl;
                break;
            }
            case Direction::kDown :
            {
                if (e._y >= _lenY - 1) {
                    break;
                }
                result._x = e._x;
                result._y = e._y + 1;
                result._value = board[result._y][result._x];
//                cout << "checking down--------" << endl;
                break;
            }
            case Direction::kLeft :
            {
                if (e._x <= 0) {
                    break;
                }
                result._x = e._x - 1;
                result._y = e._y;
                result._value = board[result._y][result._x];
//                cout << "checking left--------" << endl;
                break;
            }
            case Direction::kRight :
            {
                if (e._x >= _lenX - 1) {
                    break;
                }
                result._x = e._x + 1;
                result._y = e._y;
                result._value = board[result._y][result._x];
//                cout << "checking right--------" << endl;
                break;
            }
            default:
                break;
        }
        
//        cout << "result["<<result._x<<"]["<<result._y<<"]="<<result._value<<","<<endl;
        
        return result;
    }
    
    bool isO(const Element& e) {
        return e._value == _O;
    }
    
    bool isX(const Element& e) {
        return e._value == _X;
    }
    
    void check(vector<vector<char>>& board, int x, int y) {
        Element e;
        e._x = x;
        e._y = y;
        e._value = board[y][x];
        
        checkNear(board, e, Direction::kUp);
        checkNear(board, e, Direction::kDown);
        checkNear(board, e, Direction::kLeft);
        checkNear(board, e, Direction::kRight);
    }
    
    void checkNear(vector<vector<char>>& board, Element& e, Direction d) {
        
        Element nearE = getElementByDirection(board, e, d);
        
        if (nearE != Element_None && isO(nearE) && isO(e)) {
            
            // 设置连接点
            auto ite = find(_connected.begin(), _connected.end(), e);
            if ( ite == _connected.end()) {
                e._connected[d] = 1;
                _connected.push_back(e);
            }
            else {
                ite->_connected[d] = 1;
            }
            
//            auto ite = find(_connected.begin(), _connected.end(), nearE);
//            if ( ite == _connected.end()) {
//                nearE._connected[d] = 1;
//                _connected.push_back(nearE);
//            }
//            else {
//                ite->_connected[d] = 1;
//            }
        }
    }
    
};


int main(int argc, const char * argv[]) {
    
    string str =
"\
X X X X\n\
X O O X\n\
X X O X\n\
X O X X\n\
";
//"\
//a b c d\n\
//X O O X\n\
//X X O X\n\
//X O X X\n\
//";
    auto array = String_TwoDimensionalArray(str, " ", "\n");
    
    vector<vector<char>> board;
    
    for (auto& vec_string : array) {
        auto vec_char = VecString_VecChar(vec_string);
        if (vec_char.size()) {
            board.push_back(vec_char);
        }
    }
//    cout << TwoDimensionalArray_String(array, " ", "\n");
//    
    
    Solution s;
    s.solve(board);
    
    return 0;
}
