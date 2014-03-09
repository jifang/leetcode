//
//  Merge_Two_Sorted_Lists.h
//  LeetCode
//
//	Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

//  Created by Fish on 3/8/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Merge_Two_Sorted_Lists_h
#define LeetCode_Merge_Two_Sorted_Lists_h

#include "Tree.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	RUN
	
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
        if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		
		ListNode * head = NULL;
		if (l1->val < l2->val)
		{
			head = l1;
			l1 = l1->next;
		}
		else
		{
			head = l2;
			l2 = l2->next;
		}
		
		ListNode * p = head;
		
		while (l1 != NULL & l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				p = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				p = l2;
				l2 = l2->next;
			}
		}

		p->next = l1 ? : l2;
		
		return head;
    }
};

#endif
