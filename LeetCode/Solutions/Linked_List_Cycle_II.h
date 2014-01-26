//
//  Linked_List_Cycle_II.h
//  LeetCode
//
//  Created by Fish on 1/12/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Linked_List_Cycle_II__h
#define LeetCode_Linked_List_Cycle_II__h

#include <map>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	
	static void run() {
		Solution s;
		s.detectCycle(NULL);
	}

	ListNode *detectCycle(ListNode *head) {
		
		std::map<ListNode *, bool> nodeInfo;
		
		while (head != NULL) {
			if (nodeInfo.find(head) != nodeInfo.end())
				return head;
			
			nodeInfo[head] = true;
			head = head->next;
		}
		
		return NULL;
    }
};

#endif
