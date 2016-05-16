//
//  NextPermutation.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        
        int n = static_cast<int>(nums.size()) - 1, k = -1;
        for(int i = n - 1; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1]){
                k = i;
                break;
            }
        }
        
        if(k == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int l = -1;
        for(int i = n; i > k; i--)
        {
            if(nums[i] > nums[k]){
                l = i;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};