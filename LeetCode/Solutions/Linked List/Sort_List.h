//
//  Sort_List.h
//  LeetCode
//
//  Created by Fish on 3/7/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Sort_List_h
#define LeetCode_Sort_List_h

#include "Tree.h"

class Solution {
public:
	RUN
    ListNode * sortList(ListNode *head)
	{
		if (!head)
			return NULL;
		
		ListNode * sortedHead = head;
		ListNode * sortedEnd = head;
		ListNode * toBeInserted = head->next;
		
		while (toBeInserted) {
			
			sortedEnd->next = toBeInserted->next;
			toBeInserted->next = NULL;
			
			insertIntoSortedList(sortedHead, sortedEnd, toBeInserted);
			toBeInserted = sortedEnd->next;
		}
		
		return sortedHead;
    }
	
private:
	void insertIntoSortedList(ListNode * &head, ListNode * &end, ListNode * toBeInserted)
	{
		if (!head || ! toBeInserted || !end)
			return;
		
		if (toBeInserted->val >= end->val)
		{
			toBeInserted->next = end->next;
			end->next = toBeInserted;
			end = toBeInserted;
		}
		else if (toBeInserted->val < head->val)
		{
			toBeInserted->next = head;
			head = toBeInserted;
		}
		else
		{
			ListNode * curr = head;
			ListNode * prev = curr;
			
			while (toBeInserted->val >= curr->val) {
				prev = curr;
				curr = curr->next;
			}
			
			toBeInserted->next = curr;
			prev->next = toBeInserted;
		}
	}
	
};

#endif
