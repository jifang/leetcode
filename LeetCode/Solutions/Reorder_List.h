//
//  Reorder_List.h
//  LeetCode
//
//  Created by Fish on 1/26/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Reorder_List_h
#define LeetCode_Reorder_List_h

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	static void run () {
		Solution s;
		ListNode n1(1);
		ListNode n2(2);
		ListNode n3(3);
		ListNode n4(4);
		ListNode n5(5);
		ListNode n6(6);
		ListNode n7(7);
		
//		n1.next = &n2;
//		n2.next = &n3;
//		n3.next = &n4;
//		n4.next = &n5;
//		n5.next = &n6;
//		n6.next = &n7;
		
		s.reorderList(&n1);
		
		ListNode * p = &n1;
		while (p != NULL) {
			cout << p->val << endl;
			p = p->next;
		}
	}
	
    void reorderList(ListNode *head)
	{
		if (!head || !head->next)
			return;
		
		bool odd = false;
        ListNode * pSlow = head;
		ListNode * pFast = head;
		ListNode * pList1End = head;
		ListNode * pList2Begin = head;
		
		while (pFast != NULL)
		{
			pList1End = pSlow;
			pFast = pFast->next;
			if (pFast == NULL)
			{
				odd = true;
				break;
			}
			pFast = pFast->next;
			pSlow = pSlow->next;
		}
		pList2Begin = pList1End->next;

		// Reverse the List2
		ListNode * pNode = pList2Begin->next;
		ListNode * pPrev = pList2Begin;
		pList2Begin->next = NULL;
		
		while (pNode != NULL)
		{
			ListNode * pNext = pNode->next;
			pNode->next = pPrev;
			pPrev = pNode;
			pNode = pNext;
		}

		pList1End->next = NULL;
		pList2Begin->next = NULL;
		pList2Begin = pPrev;
		
		ListNode * pList1 = head;
		ListNode * pList2 = pList2Begin;
		
		while (pList1 != NULL)
		{
			if (odd && pList1 == pList1End)
			{
				return;
			}
			
			ListNode * pTemp = pList2->next;
			pList2->next = pList1->next;
			pList1->next = pList2;
			pList1 = pList2->next;
			pList2 = pTemp;
		}
    }
};

#endif
