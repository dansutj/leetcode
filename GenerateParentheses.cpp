//
//  GenerateParentheses.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        backTracking("", n, 0);
        return res;
    }
    
    void backTracking(string s, int n, int m)
    {
        if(n == 0 && m == 0)
        {
            res.push_back(s);
            return;
        }
        
        if(m > 0) backTracking(s + ")", n, m - 1);
        if(n > 0) backTracking(s + "(", n - 1, m + 1);
    }
    
private:
    vector<string> res;
};
