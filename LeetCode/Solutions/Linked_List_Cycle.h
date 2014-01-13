//
//  Linked_List_Cycle.h
//  LeetCode
//
//  Created by Fish on 1/12/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Linked_List_Cycle_h
#define LeetCode_Linked_List_Cycle_h

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	
	static void run() {
		Solution s;
		s.hasCycle(NULL);
	}
	
    bool hasCycle(ListNode *head) {
        ListNode * pNode1 = head;
		ListNode * pNode2 = head;
		
		while (pNode1 != NULL && pNode2 != NULL) {
			pNode1 = pNode1->next;
			pNode2 = (pNode2->next) ? (pNode2->next->next) : NULL;
			
			if (pNode1 == pNode2 && pNode1 != NULL)
				return true;
			
		}
		
		return false;
    }
};

#endif
