//
//  RemoveDuplicatesfromSortedArray.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <vector>
using namespace std;


class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.empty()) return 0;
        
        int count = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i - 1] == nums[i])
                count++;
            
            else nums[i - count] = nums[i];
        }
        return static_cast<int>(nums.size()) - count;
    }
};