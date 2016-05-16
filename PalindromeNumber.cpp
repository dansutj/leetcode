//
//  PalindromeNumber.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <string>
#include <sstream>
using namespace std;


class Solution
{
public:
    bool isPalindrome(int x)
    {
        stringstream ss;
        ss << x;
        string s = ss.str();
        int end = static_cast<int>(s.size()) - 1;
        int begin = 0;
        
        while(begin < end) if(s[begin++] != s[end--]) return false;
        return true;
        
    }
};