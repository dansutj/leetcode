//
//  TwoSum.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res;
        if(nums.empty()) return res;
        
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++)
        {
            int numToFind = target - nums[i];
            if(hashMap.find(numToFind) != hashMap.end())
            {
                res.push_back(hashMap[numToFind]);
                res.push_back(i);
                break;
            }
            hashMap[nums[i]] = i;
        }
        return res;
    }
};
