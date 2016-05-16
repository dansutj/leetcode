//
//  MergekSortedLists.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.empty()) return NULL;
        int len = static_cast<int>(lists.size());
        
        while(len > 1)
        {
            for(int i = 0; i < len / 2; i++){
                lists[i] = mergeList(lists[i], lists[len - i - 1]);
            }
            len = (len + 1) / 2;
        }
        return lists[0];
    }
    
    ListNode* mergeList(ListNode* first, ListNode* second)
    {
        if(!first) return second;
        else if(!second) return first;
        
        if(first->val < second->val)
        {
            first->next = mergeList(first->next, second);
            return first;
        }
        else
        {
            second->next = mergeList(first, second->next);
            return second;
        }
    }
};
