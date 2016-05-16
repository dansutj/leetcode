//
//  ValidParentheses.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> paren;
        for(char c : s)
        {
            if(c == '(' || c == '[' || c == '{') paren.push(c);
            else if(c == ')' && !paren.empty() && paren.top() == '(') paren.pop();
            else if(c == ']' && !paren.empty() && paren.top() == '[') paren.pop();
            else if(c == '}' && !paren.empty() && paren.top() == '{') paren.pop();
            else return false;
        }
        return paren.empty();
    }
};
