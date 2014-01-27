//
//  Symmetric_Tree.h
//  LeetCode
//
//  Created by Fish on 1/26/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Symmetric_Tree_h
#define LeetCode_Symmetric_Tree_h

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	
	static void run() {
		Solution s;
		s.isSymmetric(NULL);
	}
	
    bool isSymmetric_R(TreeNode * left, TreeNode * right)
	{
		if (left == right)
			return true;
		
		if (left && right)
		{
			return (left->val == right->val) && isSymmetric_R(left->left, right->right) && isSymmetric_R(left->right, right->left);
		}
		else
		{
			return false;
		}
    }
	
	bool isSymmetric(TreeNode *root)
	{
		if (!root)
			return true;
		
		if (root->left == NULL && root->right == NULL)
			return true;
		
		if (root->left == NULL || root->right == NULL)
			return false;
		
		vector<TreeNode *> toBeVerified;
		toBeVerified.push_back(root->left);
		toBeVerified.push_back(root->right);
				
		while (!toBeVerified.empty())
		{
			TreeNode * right = toBeVerified.back();
			toBeVerified.pop_back();
			
			TreeNode * left = toBeVerified.back();
			toBeVerified.pop_back();
			
			if (left->val != right->val)
				return false;
			
			if (left->left != NULL && right->right != NULL)
			{
				toBeVerified.push_back(left->left);
				toBeVerified.push_back(right->right);
			}
			else if (left->left != NULL || right->right != NULL)
			{
				return false;
			}
			
			if (left->right != NULL && right->left != NULL)
			{
				toBeVerified.push_back(left->right);
				toBeVerified.push_back(right->left);
			}
			else if (left->right != NULL || right->left != NULL)
			{
				return false;
			}
		}
		
		return true;
	}

};

#endif
