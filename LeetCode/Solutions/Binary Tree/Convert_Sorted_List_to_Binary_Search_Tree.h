//
//  Convert_Sorted_List_to_Binary_Search_Tree.h
//  LeetCode
//
//  Created by Fish on 1/27/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Convert_Sorted_List_to_Binary_Search_Tree_h
#define LeetCode_Convert_Sorted_List_to_Binary_Search_Tree_h

#include "Tree.h"

class Solution {
public:
	
	RUN
    
	TreeNode *sortedListToBST(ListNode *head)
	{
        if (!head)
			return NULL;
		
		if (head->next == NULL)
		{
			return new TreeNode(head->val);
		}
		
		ListNode * pSlow = head;
		ListNode * pFast = head;
		ListNode * pLeftEnd = head;
		
		while (pFast != NULL && pFast->next != NULL)
		{
			pLeftEnd = pSlow;
			pFast = pFast->next;
			if (pFast == NULL)
				break;
			pFast = pFast->next;
			pSlow = pSlow->next;
		}
		
		if (pLeftEnd != pSlow)
			pLeftEnd->next = NULL;
		
		TreeNode * root = new TreeNode(pSlow->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(pSlow->next);
		
		return root;
    }
};

#endif
