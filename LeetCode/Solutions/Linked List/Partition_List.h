//
//  Partition_List.h
//  LeetCode
//
//  Created by Fish on 3/8/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Partition_List_h
#define LeetCode_Partition_List_h

#include "Tree.h"

class Solution {
public:
	RUN
	
    ListNode *partition(ListNode *head, int x) {
    
		ListNode * p = head;
		ListNode * first = NULL;
		ListNode * prev = NULL;
		ListNode * newHead = head;
		
		while (p)
		{
			if (p->val < x)
			{
				if (first)
				{
					if (first->next == p)
					{
						first = p;
					}
					else
					{
						prev->next = p->next;
						p->next = first->next;
						first->next = p;
						first = p;
						p = prev;
					}
				}
				else if (prev)
				{
					prev->next = p->next;
					first = p;
					p->next = head;
					newHead = p;
					p = prev;
				}
				else
				{
					first = p;
				}
			}
			
			
			prev = p;
			p = p->next;
		}
		
		return newHead;
    }
};

#endif
