//
//  RemoveNthNodeFromEndofList.cpp
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(!head || !n) return head;
        
        ListNode* ahead = head;
        ListNode* behind = head;
        
        while(n--)
        {
            if(ahead)
                ahead = ahead->next;
            else break;
        }
        
        if(ahead)
        {
            while(ahead->next)
            {
                ahead = ahead->next;
                behind = behind->next;
            }
            ListNode* next = behind->next;
            behind->next = next->next;
            delete next;
        }
        
        if(n == -1 && head)
        {
            ListNode* node = head;
            head = head->next;
            delete node;
        }
        return head;
    }
};


