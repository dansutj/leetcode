//
//  ReverseNodesink-Group.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(!hasKNodes(head, k))
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* pre = &dummy;
        ListNode* cur = pre->next;
        
        while(hasKNodes(cur, k))
        {
            for(int i = 0; i < k - 1; i++)
            {
                ListNode* temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
    
    bool hasKNodes(ListNode* node, int k)
    {
        int cnt = 0;
        while(node)
        {
            cnt++;
            if(cnt >= k) return true;
            node = node->next;
        }
        return false;
    }
};
