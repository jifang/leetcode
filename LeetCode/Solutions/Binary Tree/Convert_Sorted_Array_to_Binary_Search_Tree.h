//
//  Convert_Sorted_Array_to_Binary_Search_Tree.h
//  LeetCode
//
//  Created by Fish on 1/28/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Convert_Sorted_Array_to_Binary_Search_Tree_h
#define LeetCode_Convert_Sorted_Array_to_Binary_Search_Tree_h

#include "Tree.h"

class Solution {
public:
	RUN
	
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.empty())
			return NULL;
		
		if (num.size() == 1)
			return new TreeNode(num[0]);
		
		size_t mid = num.size() / 2;
		TreeNode * root = new TreeNode(num[mid]);
		
		if (mid == 0)
		{
			root->left = NULL;
		}
		else
		{
			vector<int> left(num.begin(), num.begin()+mid);
			root->left = sortedArrayToBST(left);
		}
		
		vector<int> right(num.begin()+mid+1, num.end());
		root->right = sortedArrayToBST(right);
		
		return root;
    }
};

#endif
