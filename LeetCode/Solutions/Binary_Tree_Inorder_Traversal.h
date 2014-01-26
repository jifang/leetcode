//
//  Binary_Tree_Inorder_Traversal.h
//  LeetCode
//
//  Created by Fish on 1/25/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Binary_Tree_Inorder_Traversal_h
#define LeetCode_Binary_Tree_Inorder_Traversal_h


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void static run() {};
	
    vector<int> inorderTraversal_R(TreeNode *root) {
		
        if (root == NULL)
			return vector<int>();
		
		vector<int> left = inorderTraversal_R(root->left);
		vector<int> right = inorderTraversal_R(root->right);

		left.push_back(root->val);
		left.insert(left.end(), right.begin(), right.end());
		
		return left;
    }
	
	vector<int> inorderTraversal(TreeNode *root) {
		
		vector<int> result(0);
		vector<TreeNode *> nodes(0);
		TreeNode * stopNode = NULL;
		
		if (root)
			nodes.push_back(root);
		
		while (!nodes.empty())
		{
			TreeNode * current = nodes.back();
			nodes.pop_back();
			
			if (current->left && current != stopNode)
			{
				nodes.push_back(current);
				nodes.push_back(current->left);
			}
			else
			{
				stopNode = nodes.back();
				result.push_back(current->val);
				if (current->right)
					nodes.push_back(current->right);
			}
		}
		
		return result;
    }
};

#endif
