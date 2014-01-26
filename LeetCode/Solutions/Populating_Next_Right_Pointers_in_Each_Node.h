//
//  Populating_Next_Right_Pointers_in_Each_Node.h
//  LeetCode
//
//  Created by Fish on 1/25/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Populating_Next_Right_Pointers_in_Each_Node_h
#define LeetCode_Populating_Next_Right_Pointers_in_Each_Node_h



struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	
	static void run() {}
	
    void connect(TreeLinkNode *root)
	{
		TreeLinkNode * nextLevel = root;
		
		// Moving vertically
		while (nextLevel)
		{
			TreeLinkNode * parent = nextLevel;
			
			//Moving horizontally
			TreeLinkNode * leftSibling = NULL;
			do
			{
				TreeLinkNode * left = parent->left;
				TreeLinkNode * right = parent->right;
				
				if (left)
					left->next = right;
				
				if (leftSibling)
					leftSibling->next = left;
				
				leftSibling = right;
				
				parent = parent->next;
				
			} while (parent);
			
			nextLevel = nextLevel->left;
		}
    }
};

#endif
