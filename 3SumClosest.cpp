//
//  3SumClosest.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <vector>
#include <numeric>
#include <cmath>
using namespace std;


class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        
        if(nums.size() <= 3)
            return accumulate(nums.begin(), nums.end(), 0);
        
        int n = static_cast<int>(nums.size());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; i++)
        {
            int j = i + 1, k = n - 1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < abs(target - ans))
                {
                    ans = sum;
                    if(ans == target) return ans;
                }
                sum > target ? k-- : j++;
            }
        }
        return ans;
    }
};