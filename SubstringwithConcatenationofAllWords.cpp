//
//  SubstringwithConcatenationofAllWords.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> indexes;
        unordered_map<string, int> counts;
        
        for(string word : words) counts[word]++;
        
        int n = static_cast<int>(s.size());
        int num = static_cast<int>(words.size());
        int len = static_cast<int>(words[0].size());
        
        for(int i = 0; i < n - num * len + 1; i++)
        {
            int j = 0;
            unordered_map<string, int> seen;
            for(; j < num; j++)
            {
                string word = s.substr(i + j * len, len);
                if(counts.find(word) != counts.end())
                {
                    seen[word]++;
                    if(seen[word] > counts[word])
                        break;
                }
                else break;
            }
            if(j == num) indexes.push_back(i);
        }
        return indexes;
    }
};