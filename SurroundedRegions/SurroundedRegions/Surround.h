//
//  Surround.h
//  SurroundedRegions
//
//  Created by Fire on 15/7/21.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#ifndef SurroundedRegions_Surround_h
#define SurroundedRegions_Surround_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
    vector<Element> _alone; // 不连通的O元素
    
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
        
        cout << "===== check finish =====\n";
        
        checkSurround(board);
    }

protected:
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
        
        auto element_up = checkNear(board, e, Direction::kUp);
        auto element_down = checkNear(board, e, Direction::kDown);
        auto element_left = checkNear(board, e, Direction::kLeft);
        auto element_right = checkNear(board, e, Direction::kRight);
        
        // 孤立的元素
        if (isO(e)) {
            
            if (element_up != Element_None && element_down != Element_None &&
                element_left != Element_None && element_right != Element_None) {
                
                if (isX(element_up) && isX(element_down) && isX(element_left) && isX(element_right)) {
                    cout << "alone element" << endl;
                    _alone.push_back(e);
                }
            }
        }
    }
    
    Element checkNear(vector<vector<char>>& board, Element& e, Direction d) {
        
        Element nearE = getElementByDirection(board, e, d);
        
        // 连通的元素
        if (nearE != Element_None && isO(nearE) && isO(e)) {
            
            // 设置元素连通的方向
            auto ite = find(_connected.begin(), _connected.end(), e);
            if ( ite == _connected.end()) {
                e._connected[d] = 1;
                _connected.push_back(e);
            }
            else {
                ite->_connected[d] = 1;
            }
        }
        return nearE;
    }
    
    // 检测包围情况
    void checkSurround(vector<vector<char>>& board) {
        
        // 1.判断连通的元素是否被包围
        bool isCheckConnected = true;
        
        for (auto& e : _connected) {
            for (int i = 0; i < sizeof(e._connected) / sizeof(char); i++) {
                // 判断不连通的一侧
                if (e._connected[i] == 0) {
                    auto nextElement = getElementByDirection(board, e, (Direction)i);
                    
                    if (nextElement == Element_None || isX(nextElement) == false) {
                        isCheckConnected = false;
                        break;
                    }
                }
            }// end for
        }
        
        if (isCheckConnected) {
            for (auto& e : _connected) {
                surround(board, e._x, e._y);
            }
        }
        
        // 2.孤立的元素
        for (auto& e : _alone) {
            surround(board, e._x, e._y);
        }
    }
    
    void surround(vector<vector<char>>& board, int x, int y) {
        board[y][x] = _X;
    }
    
};

#endif
