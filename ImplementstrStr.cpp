//
//  ImplementstrStr.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = static_cast<int>(haystack.length());
        int n = static_cast<int>(needle.length());
        
        for(int i = 0; i < m - n + 1; i++)
        {
            int j = 0;
            for(; j < n; j++)
            {
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == n) return i;
        }
        return -1;
    }
};