//
//  StringtoInteger.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <limits.h>
#include <string>
using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        int i = 0, temp = 0;
        int res = 0, sign = 1;
        int n = static_cast<int>(str.length());
        if(n == 0) return 0;
        
        while(str[i] == ' ')
            i++;
        
        if(str[i] == '-'){
            sign = -1;
            i++;
        }
        else if(str[i] == '+'){
            sign = 1;
            i++;
        }
        for(; i < n; i++)
        {
            if(str[i] > '9' || str[i] < '0')
                break;
            temp = res * 10 + (str[i] - '0');
            if(temp / 10 != res)
            {
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            res = temp;
        }
        return res * sign;
    }
};