//
//  Populating_Next_Right_Pointers_in_Each_Node_II.h
//  LeetCode
//
//  Created by Fish on 1/27/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Populating_Next_Right_Pointers_in_Each_Node_II_h
#define LeetCode_Populating_Next_Right_Pointers_in_Each_Node_II_h

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
				
				
				if (leftSibling)
				{
					if (left)
					{
						leftSibling->next = left;
						leftSibling = NULL;
					}
					else if (right)
					{
						leftSibling->next = right;
						leftSibling = NULL;
					}
				}
				
				if (left)
				{
					if (right)
					{
						left->next = right;
						leftSibling = right;
					}
					else
					{
						leftSibling = left;
					}
				}
				else if (right)
					leftSibling = right;
				
				parent = parent->next;
				
			} while (parent);
			
			// Find next level
			while (nextLevel)
			{
				if (nextLevel->left)
				{
					nextLevel = nextLevel->left;
					break;
				}
				else if (nextLevel->right)
				{
					nextLevel = nextLevel->right;
					break;
				}
				nextLevel = nextLevel->next;
			}
		}
    }
};

#endif
