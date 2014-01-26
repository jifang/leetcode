//
//  Binary_Tree_Preorder_Traversal.h
//  LeetCode
//
//  Created by Fish on 1/25/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Binary_Tree_Preorder_Traversal_h
#define LeetCode_Binary_Tree_Preorder_Traversal_h

#include <stack>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void static run() {
		Solution s;
		TreeNode t(5);
		s.preorderTraversal_R(&t);
	};
	
    vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> result(0);
		stack<TreeNode *> pending;
		if (root)
			pending.push(root);
		
		while (!pending.empty())
		{
			TreeNode * current = pending.top();
			pending.pop();
			if (current->right)
				pending.push(current->right);
			if (current->left)
				pending.push(current->left);

			result.push_back(current->val);
		}
		
		return result;
    }
	
	vector<int> preorderTraversal_R(TreeNode *root) {
        
		if (!root)
			return vector<int>(0);
		
		vector<int> left = preorderTraversal_R(root->left);
		vector<int> right = preorderTraversal_R(root->right);
		
		left.insert(left.begin(), root->val);
		left.insert(left.end(), right.begin(), right.end());
		
		return left;
    }
};

#endif
