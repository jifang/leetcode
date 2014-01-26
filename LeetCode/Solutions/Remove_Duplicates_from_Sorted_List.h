//
//  Remove_Duplicates_from_Sorted_List.h
//  LeetCode
//
//  Created by Fish on 1/25/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Remove_Duplicates_from_Sorted_List_h
#define LeetCode_Remove_Duplicates_from_Sorted_List_h


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
	{
		if (!head)
			return NULL;

		int last = head->val;
		
		ListNode * pPrev = head;
		ListNode * pNode = head->next;

		while (pNode)
		{
			if (pNode->val == last)
			{
				pPrev->next = pNode->next;
			}
			else
			{
				pPrev = pNode;
				last = pNode->val;
			}
			
			pNode = pNode->next;
		}
		
		return head;
    }
};

#endif
