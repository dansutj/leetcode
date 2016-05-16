//
//  LongestSubstringWithoutRepeatingCharacters.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.empty())
            return 0;
        
        int dict[128] = {};
        
        bool repeat = false;
        int start = 0, maxLen = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(dict[s[i]]++){
                repeat = true;
                
                while(repeat){
                    if(1 == --dict[s[start++]])
                        repeat = false;
                }
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};
