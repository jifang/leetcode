//
//  Path_Sum.h
//  LeetCode
//
//  Created by Fish on 1/27/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Path_Sum_h
#define LeetCode_Path_Sum_h

#include "Tree.h"

class Solution {
public:
	static void run () {}
    bool hasPathSum(TreeNode *root, int sum)
	{
        if (!root)
			return false;
		
		if (sum == root->val && root->left == NULL && root->right == NULL)
			return true;
		
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

#endif
