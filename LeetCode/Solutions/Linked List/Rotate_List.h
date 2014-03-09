//
//  Rotate_List.h
//  LeetCode
//
//  Created by Fish on 3/9/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Rotate_List_h
#define LeetCode_Rotate_List_h

#include "Tree.h"

/**
 Given a list, rotate the list to the right by k places, where k is non-negative.
 
 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	static void run ()
	{
		ListNode * node = new ListNode(1);
		node->next = new ListNode(2);
		node->next->next = new ListNode(3);
		Solution s;
		ListNode * p = s.rotateRight(node, 2);
		
		while (p)
		{
			cout << p->val << "->";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
	
    ListNode *rotateRight(ListNode *head, int k)
	{
		if (!head || k == 0)
			return head;
		
		ListNode * p = head;
		int length = 1;
		while (p->next)
		{
			++length;
			p = p->next;
		}
		
		k = k % length;
		if (k == 0)
			return head;
		
		k = length - k;
		p->next = head;

		while (k > 0)
		{
			p = p->next;
			--k;
		}
		
		head = p->next;
		p->next = NULL;
		
		return head;
    }
};

#endif
