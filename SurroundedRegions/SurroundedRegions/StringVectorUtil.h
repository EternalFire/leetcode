//
//  StringVectorUtil.h
//  SurroundedRegions
//
//  Created by Fire on 15/7/20.
//  Copyright (c) 2015年 Fire. All rights reserved.
//

#ifndef SurroundedRegions_StringVectorUtil_h
#define SurroundedRegions_StringVectorUtil_h

#include <iostream>
#include <string>
#include <vector>
//#include <sstream>

namespace StringVectorUtil {
    
    using namespace std;
    
    vector<string> SplitStringByField(string str, const char* field) {
        vector<string> result;
        
//        while (str.find("\n") != string::npos) {
        while (str.find(field) != string::npos) {
//            auto pos = str.find("\n");
            auto pos = str.find(field);
            string data = str.substr(0, pos);
//            str = str.substr(pos + 1);
            str = str.substr(pos + strlen(field));
            result.push_back(data);
        }
        
        if (str.length()) {
            result.push_back(str);
        }
        
        return result;
    }
    
    // vector<char> => vector<string>
    vector<string> VecChar_VecString(const vector<char>& vec_char) {
        vector<string> result;
        
        for (auto& c : vec_char) {
            string s = "";
            s += c;
            result.push_back(s);
        }
        
        return result;
    }
    
    // vector<string> => vector<char>
    vector<char> VecString_VecChar(const vector<string>& vec_string) {
        vector<char> result;
        
        for (auto& s : vec_string) {
            result.push_back(*s.c_str());
        }
        
        return result;
    }
    
    vector<vector<char>> VVString_VVChar(const vector<vector<string>>& array) {
        vector<vector<char>> result;
        
        for (auto& vec_string : array) {
            auto vec_char = VecString_VecChar(vec_string);
            if (vec_char.size()) {
                result.push_back(vec_char);
            }
        }
        
        return result;
    }
    
    vector<vector<string>> VVChar_VVString(const vector<vector<char>>& board) {
        vector<vector<string>> result;
        
        for (auto& vec_char : board) {
            auto vec_string = VecChar_VecString(vec_char);
            if (vec_string.size()) {
                result.push_back(vec_string);
            }
        }
        
        return result;
    }

    
    // string => array; inField: 一行中的数据间隔符(",", "|"等), outField: 每行的间隔符("\n")
    vector<vector<string>> String_TwoDimensionalArray(const string& str, const char* inField, const char* outField) {
        
        vector<vector<string>> result;
        result.reserve(256);
        
        // 分隔每行数据
        auto rowData = SplitStringByField(str, outField);
        for (auto& sRow : rowData) {
            
            // 分隔每个数据
            auto dataVec = SplitStringByField(sRow, inField);
            vector<string> resultData;
            
            for (auto& dataum : dataVec) {
                resultData.push_back(dataum);
            }
            
            if (resultData.size()) {
                result.push_back(resultData);
            }
        }
        
        return result;
    }
    
    // array => string
    string TwoDimensionalArray_String(const vector<vector<string>>& array, const char* inField, const char* outField) {
        string result = "";
        
        for (auto& vec : array){
            for (auto& data : vec) {
                result += data; // 数据
                result += inField; // 数据间隔符
            }
            
            result += outField; // 行间隔
        }
        
        return result;
    }
    
}

#endif
