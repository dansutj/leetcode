//
//  SearchinRotatedSortedArray.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int begin = 0, end = n - 1;
        int minIndex = findMin(nums);
        
        while(begin <= end)
        {
            int mid = begin + (end - begin) / 2;
            int realMid = (mid + minIndex) % n;
            if(nums[realMid] == target) return realMid;
            if(nums[realMid] > target) end = mid - 1;
            else begin = mid + 1;
        }
        return -1;
    }
    
    int findMin(vector<int>& nums)
    {
        int begin = 0, end = static_cast<int>(nums.size()) - 1;
        while(begin < end)
        {
            int mid = begin + (end - begin) / 2;
            if(nums[mid] > nums[end]) begin = mid + 1;
            else end = mid;
        }
        return end;
    }
};