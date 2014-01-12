//
//  Same_Tree.h
//  LeetCode
//
//  Created by Fish on 1/12/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Same_Tree_h
#define LeetCode_Same_Tree_h

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	
	static void run () {
		
	}
	
    bool isSameTree(TreeNode *p, TreeNode *q) {
		
		if (p == q)
			return true;
		
		if (p == NULL || q == NULL)
			return false;
		
		return (p->val == q->val) &&
			   isSameTree(p->left, q->left) &&
			   isSameTree(p->right, q->right);
    }
};

#endif
