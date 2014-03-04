//
//  Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.h
//  LeetCode
//
//  Created by Fish on 1/28/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_h
#define LeetCode_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_h

#include "Tree.h"

class Solution {
public:
	RUN
	
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		return buildTreeR(inorder, postorder, 0, 0, inorder.size());
	}
	
    TreeNode *buildTreeR(vector<int> &inorder, vector<int> &postorder, int iStart, int pStart, int size)
	{
		if (size == 0)
			return NULL;
		
		TreeNode * root = new TreeNode(postorder[pStart+size-1]);
		
		if (size == 1)
			return root;
		
		int i = 0;
		int leftSize = 0;
		for (i = iStart; i < (iStart + size); ++i)
		{
			if (inorder[i] == root->val)
				break;
			
			++leftSize;
		}
		int rightSize = size - leftSize - 1;
		
		vector<int> leftInOrder = vector<int>(inorder.begin(), inorder.begin() + i);
		vector<int> rightInOrder = vector<int>(inorder.begin() + i + 1, inorder.end());
		vector<int> leftPostOrder = vector<int>(postorder.begin(), postorder.begin() + i);
		vector<int> rightPostOrder = vector<int>(postorder.begin() + i, postorder.end() - 1);
		
		root->left = buildTreeR(inorder, postorder, iStart, pStart, leftSize);
		root->right = buildTreeR(inorder, postorder, iStart + leftSize + 1, pStart + leftSize, rightSize);
		
		return root;
    }
};

#endif
