//
//  Binary_Tree_Postorder_Traversal.h
//  LeetCode
//
//  Created by Fish on 1/25/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Binary_Tree_Postorder_Traversal_h
#define LeetCode_Binary_Tree_Postorder_Traversal_h

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
		s.postorderTraversal(&t);
	}
    vector<int> postorderTraversal_R(TreeNode *root)
	{
        if (!root)
			return vector<int>(0);
		
		vector<int> left = postorderTraversal_R(root->left);
		vector<int> right = postorderTraversal_R(root->right);
		
		left.insert(left.end(), right.begin(), right.end());
		left.push_back(root->val);
		
		return left;
    }
	
	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> result(0);
		stack<TreeNode *> pending;
		if (root)
			pending.push(root);
		
		while (!pending.empty())
		{
			TreeNode * current = pending.top();
			pending.pop();
			
			if (current->left)
				pending.push(current->left);
			if (current->right)
				pending.push(current->right);

			result.insert(result.begin(), current->val);
		}
		
		return result;
	}

};

#endif
