//
//  SwapNodesinPairs.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode **point = &head, *cur, *next;
        while((cur = *point) && (next = cur->next))
        {
            cur->next = next->next;
            next->next = cur;
        }
        return head;
    }
};
