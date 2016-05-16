//
//  4Sum.cpp
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
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if(nums.size() < 4) return result;
        int n = static_cast<int>(nums.size());
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++)
        {
            if(i == 0 || nums[i] != nums[i-1])
            {
                for(int j = i + 1; j < n - 2; j++)
                {
                    if(j == i + 1 || nums[j] != nums[j-1])
                    {
                        int lo = j + 1;
                        int hi = n - 1;
                        while(lo < hi)
                        {
                            int sum = nums[i] + nums[j] + nums[lo] + nums[hi];
                            if(sum == target)
                            {
                                result.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                                while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                                while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                                lo++; hi--;
                            }
                            else if(sum < target) lo++;
                            else hi--;
                        }
                    }
                }
            }
        }
        return result;
    }
private:
    vector<vector<int>> result;
};