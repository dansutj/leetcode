//
//  ZigZagConversion.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        if(numRows <= 1) return s;
        
        int row = 0, step = 0;
        int len = static_cast<int>(s.length());
        string *str = new string[numRows];
        
        for(int i = 0; i < len; i++)
        {
            str[row] += s[i];
            if(row == 0) step = 1;
            else if(row == numRows - 1) step = -1;
            row += step;
        }
        s.clear();
        for(int i = 0; i < numRows; i++) s.append(str[i]);
        return s;
    }
};
