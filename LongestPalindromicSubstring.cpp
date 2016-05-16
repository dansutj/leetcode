//
//  LongestPalindromicSubstring.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        
        int n = static_cast<int>(s.length());
        if(n < 2) return s;
        
        int start = 0, maxLen = 1;
        for(int i = 0; i < n;)
        {
            if(n - i <= maxLen / 2)
                break;
            
            int lo = i, hi = i;
            while(hi + 1 < n && s[hi + 1] == s[hi]) hi++;
            
            i = hi + 1;
            while(hi < n - 1 && lo > 0 && s[lo - 1] == s[hi + 1]){
                hi++; lo--;
            }
            
            int len = hi - lo + 1;
            if(maxLen < len)
            {
                maxLen = len;
                start = lo;
            }
        }
        return s.substr(start, maxLen);
    }
};
