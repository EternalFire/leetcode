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
#include <queue>

using namespace std;

class Solution {
protected:
    char _O;
    char _X;
    char _P;
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
    vector<Element> _delVec;
    queue<Element> _queCheck;
    
public:
    Solution():_lenX(0), _lenY(0), _O('O'), _X('X'), _P('P'){}
    
    void solve(vector<vector<char>>& board) {
        
//        solveWithCheckInside(board);
        solveWithCheckBorder(board);
    }

protected:
    void solveWithCheckInside(vector<vector<char>>& board) {
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
        
        surround(board);
    }
    
    void solveWithCheckBorder(vector<vector<char>>& board) {
        if (isValid(board) == false) {
            return;
        }
        
        // 判断边界的O元素, 和 O元素连通的O元素
        for (int y = 0; y < _lenY; y++) {
            checkFromBorder(board, 0, y);
            checkFromBorder(board, _lenX - 1, y);
        }
        
        for (int x = 1; x < _lenX - 1; x++) {
            checkFromBorder(board, x, 0);
            checkFromBorder(board, x, _lenY - 1);
        }
        
        while (!_queCheck.empty()) {
            Element e = _queCheck.front();
            _queCheck.pop();
            checkNearFromBorder(board, e, Direction::kUp);
            checkNearFromBorder(board, e, Direction::kDown);
            checkNearFromBorder(board, e, Direction::kLeft);
            checkNearFromBorder(board, e, Direction::kRight);
        }

//        for (int y = 1; y < _lenY - 1; y++) {
//            for (int x = 1; x < _lenX - 1; x++) {
        for (int y = 0; y < _lenY; y++) {
            for (int x = 0; x < _lenX; x++) {
                if (board[y][x] == _O) {
                    board[y][x] = _X;
                }
                else if (board[y][x] == _P) { /// 处理标记
                    board[y][x] = _O;
                }
            }
        }
        
        return; /// 只处理标记, 不处理_connected
        
        for (auto ite = _connected.begin(); ite != _connected.end(); ite++) {
            board[ite->_y][ite->_x] = _O;
        }
    }
    
    // 二维数组大小在 x, y 方向 都大于等于3时, 才能实现包围
    inline bool isValid(const vector<vector<char>>& board) {
        int valid_len = 3;
        
        if (board.size() < valid_len || board[0].size() < valid_len) {
            return false;
        }
        else {
            init(board);
            return true;
        }
    }
    
    inline void init(const vector<vector<char>>& board) {
        _lenX = (int)board.begin()->size();
        _lenY = (int)board.size();
    }
    
    // 返回元素(e), 在某方向相邻的元素
    Element getElementByDirection(vector<vector<char>>& board, const Element& e, Direction d) {
        
        Element result;
        
//        if (e._y <= 0 || e._y >= _lenY - 1 || e._x <= 0 || e._x >= _lenX - 1) {
        if (e._y < 0 || e._y > _lenY - 1 || e._x < 0 || e._x > _lenX - 1) {
            return result;
        }
        
        pair<int, int> coord[4] = {
            {e._x, e._y - 1},
            {e._x, e._y + 1},
            {e._x - 1, e._y},
            {e._x + 1, e._y},
        };
        
        if (!(coord[d].first >=0 && coord[d].first < _lenX &&
            coord[d].second >= 0 && coord[d].second < _lenY)) {
            return result;
        }
        
        result._x = coord[d].first;
        result._y = coord[d].second;
        result._value = board[result._y][result._x];
    
//        switch (d) {
//            case Direction::kUp :
//            {
//                if (e._y <= 0) {
//                    break;
//                }
//                result._x = e._x;
//                result._y = e._y - 1;
//                result._value = board[result._y][result._x];
//                break;
//            }
//            case Direction::kDown :
//            {
//                if (e._y >= _lenY - 1) {
//                    break;
//                }
//                result._x = e._x;
//                result._y = e._y + 1;
//                result._value = board[result._y][result._x];
//                break;
//            }
//            case Direction::kLeft :
//            {
//                if (e._x <= 0) {
//                    break;
//                }
//                result._x = e._x - 1;
//                result._y = e._y;
//                result._value = board[result._y][result._x];
//                break;
//            }
//            case Direction::kRight :
//            {
//                if (e._x >= _lenX - 1) {
//                    break;
//                }
//                result._x = e._x + 1;
//                result._y = e._y;
//                result._value = board[result._y][result._x];
//                break;
//            }
//            default:
//                break;
//        }
        
        return result;
    }
    
    inline bool isO(const Element& e) {
        return e._value == _O;
    }
    
    inline bool isX(const Element& e) {
        return e._value == _X;
    }
    
    void checkFromBorder(vector<vector<char>>& board, int x, int y) {
        if (board[y][x] == _X) {
            return;
        }
        
        Element e;
        e._x = x;
        e._y = y;
        e._value = board[y][x];
        
//        checkNearFromBorder(board, e, Direction::kUp);
//        checkNearFromBorder(board, e, Direction::kDown);
//        checkNearFromBorder(board, e, Direction::kLeft);
//        checkNearFromBorder(board, e, Direction::kRight);
        _queCheck.push(e);
    }
    
    Element checkNearFromBorder(vector<vector<char>>& board, Element& e, Direction d) {
        Element nearE;
        
//        if (isX(e)) {
//            return nearE;
//        }
        if (isO(e)) {
            board[e._y][e._x] = _P;
        }
        
        nearE = getElementByDirection(board, e, d);
        // 连通的元素
        if (nearE != Element_None && isO(nearE) && isO(e)) {
            
            /// 只标记, 不保存, begin
//            board[e._y][e._x] = _P;
            board[nearE._y][nearE._x] = _P;
            _queCheck.push(nearE);
            return nearE;
            /// end
            
            bool findIt = getConnectedElement(e);
            if (e._connected[d] == 1) {
                return nearE;
            }
            
            bool findIt_1 = getConnectedElement(nearE);
            
            if (findIt && findIt_1) {
                return nearE;
            }
            
            if (findIt)
                _connected.erase(find(_connected.begin(), _connected.end(), e));
            
            if (findIt_1)
                _connected.erase(find(_connected.begin(), _connected.end(), nearE));
            
            int nearDirection = 0;
            if (d == Direction::kUp) {
                nearDirection = Direction::kDown;
            }
            else if (d == Direction::kDown){
                nearDirection = Direction::kUp;
            }
            else if (d == Direction::kLeft) {
                nearDirection = Direction::kRight;
            }
            else if (d == Direction::kRight) {
                nearDirection = Direction::kLeft;
            }
            
            e._connected[d] = 1;
            nearE._connected[nearDirection] = 1;
            _connected.push_back(nearE);
            _connected.push_back(e);
//            checkFromBorder(board, nearE._x, nearE._y);
            _queCheck.push(nearE);
        }
        return nearE;
    }
    
    bool getConnectedElement(Element& e) {
        bool findIt = false;
        
        for (auto ite = _connected.begin(); ite != _connected.end(); ite++) {
            if (e._x == ite->_x && e._y == ite->_y) {
                e = *ite;
                findIt = true;
                break;
            }
        }
        return findIt;
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
                check(board, nearE._x, nearE._y);
            }
            else {
                ite->_connected[d] = 1;
            }
        }
        return nearE;
    }
    
    // 检测包围情况
    void checkSurround(vector<vector<char>>& board) {
        
        // 判断连通的元素是否被包围
        for (auto& e : _connected) {
            for (int i = 0; i < sizeof(e._connected) / sizeof(char); i++) {
                // 判断不连通的一侧
                if (e._connected[i] == 0) {
                    auto nextElement = getElementByDirection(board, e, (Direction)i);
                    
                    if (nextElement == Element_None || isX(nextElement) == false) {
                        
                        if (nextElement == Element_None) {
                            delConnected(board, e);
                        }
                        
                        break;
                    }
                }
            }// end for
        }
        
        for (auto delE : _delVec) {
            _connected.erase(find(_connected.begin(), _connected.end(), delE));
        }
        
        _delVec.clear();
    }
    
    void delConnected(vector<vector<char>>& board, Element& e) {
        
        if (find(_delVec.begin(), _delVec.end(), e) == _delVec.end()) {
            _delVec.push_back(e);
        }
        
        for (int i = 0; i < sizeof(e._connected) / sizeof(char); i++) {
            
            if (e._connected[i] == 1) {
                auto nextElement = getElementByDirection(board, e, (Direction)i);
                
                for (auto ite = _connected.begin(); ite != _connected.end(); ite++) {
                    if (nextElement._x == ite->_x && nextElement._y == ite->_y) {
                        nextElement = *ite;
                    }
                }
                
                if (find(_delVec.begin(), _delVec.end(), nextElement) == _delVec.end()) {
                    _delVec.push_back(nextElement);
                    delConnected(board, nextElement);
                }
                else {
                    break;
                }
            }
        }
    }
    
    void surround(vector<vector<char>>& board) {
        for (auto& e : _connected) {
            board[e._y][e._x] = _X;
        }
        
        for (auto& e : _alone) {
            board[e._y][e._x] = _X;
        }
    }
    
};

#endif
