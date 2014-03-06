//
//  Validate_Binary_Search_Tree.h
//  LeetCode
//
//  Created by Fish on 3/6/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Validate_Binary_Search_Tree_h
#define LeetCode_Validate_Binary_Search_Tree_h

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
    bool isValidBST(TreeNode *root)
	{
        TreeNode * currentMax = NULL;
		return inOrderTraverse(root, currentMax);
    }
	
	bool inOrderTraverse(TreeNode * root, TreeNode * &currentMax)
	{
		if (!root)
			return true;
		
		if (currentMax && currentMax->val >= root->val)
			return false;
		
		bool result = true;
		if (root->left)
			result = inOrderTraverse(root->left, currentMax);
		
		if (!result)
			return false;
		
		if (currentMax && currentMax->val >= root->val)
			return false;
		
		currentMax = root;
		
		return inOrderTraverse(root->right, currentMax);
	}
};

#endif
