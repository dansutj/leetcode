//
//  AddTwoNumbers.cpp
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(!l1) return l2;
        else if(!l2) return l1;
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        int sum = 0;
        while(l1 || l2 || sum)
        {
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            sum /= 10;
        }
        return dummy.next;
    }
};
