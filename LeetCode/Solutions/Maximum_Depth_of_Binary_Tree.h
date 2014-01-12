//
//  Maximum_Depth_of_Binary_Tree.h
//  LeetCode
//
//  Created by Fish on 1/12/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Maximum_Depth_of_Binary_Tree_h
#define LeetCode_Maximum_Depth_of_Binary_Tree_h

#include <algorithm> 

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root)
			return 0;
		
		return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

#endif
