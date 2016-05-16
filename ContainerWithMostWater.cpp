//
//  ContainerWithMostWater.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height)
    {
        if(height.empty()) return 0;
        
        int maxSize = 0;
        int lo = 0, hi = static_cast<int>(height.size()) - 1;
        
        while(lo < hi)
        {
            int h = min(height[lo], height[hi]);
            maxSize = max(maxSize, h * (hi - lo));
            
            while(height[lo] <= h && lo < hi) lo++;
            while(height[hi] <= h && lo < hi) hi--;
        }
        return maxSize;
    }
};
