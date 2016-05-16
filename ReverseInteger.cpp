//
//  ReverseInteger.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//
#include <limits.h>

class Solution
{
public:
    int reverse(int x)
    {
        long long res = 0;
        
        while(x)
        {
            res =res*10 + x%10;
            x /= 10;
        }
        return (res >= INT_MAX || res <= INT_MIN) ? 0 : static_cast<int>(res);
    }
};
