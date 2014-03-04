//
//  Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.h
//  LeetCode
//
//  Created by Fish on 3/4/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_h
#define LeetCode_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_h

#include "Tree.h"

class Solution {
public:
	RUN
	
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeR(preorder, inorder, 0, 0, inorder.size());
    }
	
	TreeNode *buildTreeR(vector<int> &preorder, vector<int> &inorder, int pStart, int iStart, int size)
	{
		if (size == 0)
			return NULL;
		
		TreeNode * root = new TreeNode(preorder[pStart]);
		
		if (size == 1)
			return root;
		
		int i = 0;
		int leftSize = 0;
		for (i = iStart; i < iStart + size; ++i)
		{
			if (inorder[i] == root->val)
				break;
			++leftSize;
		}
		int rightSize = size - leftSize - 1;
		
		root->left = buildTreeR(preorder, inorder, pStart + 1, iStart, leftSize);
		root->right = buildTreeR(preorder, inorder, pStart + leftSize + 1, iStart + leftSize + 1, rightSize);
		
		return root;
    }
};
#endif
