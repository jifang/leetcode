//
//  Merge_k_Sorted_Lists.h
//  LeetCode
//
//	Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
//  Created by Fish on 3/8/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Merge_k_Sorted_Lists_h
#define LeetCode_Merge_k_Sorted_Lists_h

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
	static void run ()
	{
		Solution s;
		vector<ListNode *> lists(0);
		ListNode * first = new ListNode(1);
		first->next = new ListNode(2);
		first->next->next = new ListNode(2);
		
		ListNode * second = new ListNode(1);
		second->next = new ListNode(1);
		second->next->next = new ListNode(2);
		
		lists.push_back(new ListNode(2));
		lists.push_back(first);
		lists.push_back(new ListNode(-1));

		s.mergeKLists(lists);
	}
	
    ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		if (lists.empty())
			return NULL;
		
		std::sort(lists.begin(), lists.end(), &Solution::compare);
		
		ListNode * head = lists.front();
		ListNode * p = head;
		this->pop(lists);

		while (p && !lists.empty())
		{
			ListNode * currMin = lists[0];
			p->next = currMin;
			p = currMin;
			this->pop(lists);
		}
		
		p = head;
		while (p != NULL) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
		return head;
    }
	
private:
	// Heap implemenation
	void pop(vector<ListNode *> &lists)
	{
		if (lists.empty())
			return;
		
		if (lists[0] == NULL)
			return;
		
		lists[0] = lists[0]->next;
		
		unsigned long i = 0;
		while (i < lists.size())
		{
			ListNode * parent = lists[i];
			unsigned long child1 = 2 * i + 1;
			unsigned long child2 = 2 * i + 2;
			
			if (child1 < lists.size())
			{
				unsigned long  min = child1;

				if (child2 < lists.size())
				{
					if (Solution::compare(lists[child2], lists[child1]))
						min = child2;
				}
				
				if (Solution::compare(lists[min], parent))
				{
					lists[i] = lists[min];
					lists[min] = parent;
					i = min;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	
	// -1 if node1 < node2, 0 if node1 == node2, 1 if node1 > node2
	// NULL is treated as infinite here
	static bool compare(ListNode * node1, ListNode * node2)
	{
		if (node1 == NULL)
			return false;
		if (node2 == NULL)
			return true;
		
		return node1->val < node2->val;
	}
};

#endif
