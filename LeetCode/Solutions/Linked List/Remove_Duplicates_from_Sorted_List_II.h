//
//  Remove_Duplicates_from_Sorted_List_II.h
//  LeetCode
//
//  Created by Fish on 3/8/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Remove_Duplicates_from_Sorted_List_II_h
#define LeetCode_Remove_Duplicates_from_Sorted_List_II_h

#include "Tree.h"

class Solution {
public:
	RUN
	
    ListNode *deleteDuplicates(ListNode *head)
	{
		if (!head)
			return NULL;
		
		ListNode * checked = NULL;
		ListNode * parentOfChecked = NULL;
		ListNode * newHead = head;
		ListNode * p = head;
		bool dupEncounted = false;
		
		while (p)
		{
			if (!checked || p->val != checked->val)
			{
				if (dupEncounted)
				{
					if (!parentOfChecked)
					{
						newHead = p;
					}
					else
					{
						parentOfChecked->next = p;
					}
				}
				else
				{
					if (parentOfChecked)
						parentOfChecked = parentOfChecked->next;
					else if (p != newHead)
						parentOfChecked = checked;
				}
				
				checked = p;
				dupEncounted = false;
			}
			else
			{
				dupEncounted = true;
			}
			
			p = p->next;
		}
		
		if (dupEncounted)
		{
			if (parentOfChecked)
				parentOfChecked->next = NULL;
			else
				return NULL;
		}
		
		return newHead;
    }
	
};

#endif
