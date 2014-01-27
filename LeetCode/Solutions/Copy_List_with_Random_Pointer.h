//
//  Copy_List_with_Random_Pointer.h
//  LeetCode
//
//  Created by Fish on 1/26/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Copy_List_with_Random_Pointer_h
#define LeetCode_Copy_List_with_Random_Pointer_h

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	static void run() {}
	
    RandomListNode *copyRandomList(RandomListNode *head)
	{
		RandomListNode * prev = NULL;
		RandomListNode * pNode = head;
		
        while (pNode)
		{
			RandomListNode * cloned = new RandomListNode(pNode->label);
			nodeMap[pNode] = cloned;
			
			if (prev)
				prev->next = cloned;
			
			prev = cloned;
			pNode = pNode->next;
		}
		
		pNode = head;
		while (pNode)
		{
			RandomListNode * cloned = nodeMap[pNode];
			cloned->random = pNode->random ? nodeMap[pNode->random] : NULL;
			pNode = pNode->next;
		}
		
		return nodeMap[head];
    }
	
private:
	map<RandomListNode *, RandomListNode *> nodeMap;
};

#endif
