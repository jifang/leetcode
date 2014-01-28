//
//  Minimum_Depth_of_Binary_Tree.h
//  LeetCode
//
//  Created by Fish on 1/27/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Minimum_Depth_of_Binary_Tree_h
#define LeetCode_Minimum_Depth_of_Binary_Tree_h

#include "Tree.h"

class Solution {
public:
	
	RUN
	
    int minDepth(TreeNode *root) {
        if (!root)
			return 0;
		
		if (!root->left && !root->right)
			return 1;
		
		if (!root->left)
			return 1 + minDepth(root->right);
		if (!root->right)
			return 1 + minDepth(root->left);
		
		return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

#endif
