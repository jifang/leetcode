//
//  Flatten_Binary_Tree_to_Linked_List.h
//  LeetCode
//
//  Created by Fish on 3/4/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Flatten_Binary_Tree_to_Linked_List_h
#define LeetCode_Flatten_Binary_Tree_to_Linked_List_h

#include "Tree.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	
	RUN
	
    void flatten(TreeNode *root)
	{
		TreeNode * node = root;
		while (node && (node->left || node->right))
		{
			TreeNode * left = node->left;
			if (left)
			{
				while (left->right)
				{
					left = left->right;
				}
				left->right = node->right;
				node->right = node->left;
				node->left = NULL;
			}
			node = node->right;
		}
    }
};

#endif
