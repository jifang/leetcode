//
//  Reverse_Linked_List_II.h
//  LeetCode
//
//  Created by Fish on 3/8/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Reverse_Linked_List_II_h
#define LeetCode_Reverse_Linked_List_II_h

#include "Tree.h"

class Solution {
public:
	
	RUN
	
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		
		if (!head || !head->next)
			return head;
		
        ListNode * p = head;
		ListNode * prev = NULL;
		ListNode * start = NULL;

		int step = 1;
		
		while (true)
		{
			ListNode * next = p->next;

			if (step == m)
				start = p;
			
			if (step >= m && step <= n)
			{
				p->next = prev;
				
				if (step == n)
				{
					if (start->next)
						start->next->next = p;
					start->next = next;
					return (m == 1) ? p : head;
				}
			}
			
			++step;
			prev = p;
			p = next;
		}
		
		return NULL;
    }
};

#endif
