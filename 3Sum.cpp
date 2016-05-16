//
//  3Sum.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        
        for(int i = 0; i < n - 2; i++)
        {
            if(i == 0 || nums[i] != nums[i-1])
            {
                int lo = i + 1, hi = n - 1, sum = -nums[i];
                while(lo < hi)
                {
                    if(nums[lo] + nums[hi] == sum)
                    {
                        result.push_back({nums[i], nums[lo], nums[hi]});
                        while(lo < hi && nums[hi] == nums[hi-1]) hi--;
                        while(lo < hi && nums[lo] == nums[lo+1]) lo++;
                        hi--; lo++;
                    }
                    else if(nums[lo] + nums[hi] < sum) lo++;
                    else hi--;
                }
            }
        }
        return result;
    }
private:
    vector<vector<int>> result;
};