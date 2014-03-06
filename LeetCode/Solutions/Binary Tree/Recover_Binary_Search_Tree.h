//
//  Recover_Binary_Search_Tree.h
//  LeetCode
//
//  Created by Fish on 3/4/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Recover_Binary_Search_Tree_h
#define LeetCode_Recover_Binary_Search_Tree_h

#include "Tree.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	static void run() {
		Solution s;
		TreeNode * node1 = new TreeNode(0);
		TreeNode * node2 = new TreeNode(1);
		node1->right = node2;
		s.recoverTree(node1);
	}
	
	// Space O(n)
    void recoverTree(TreeNode *root)
	{
		vector<TreeNode *> queue(0);
		queue.reserve(100);
		traverse(root, queue);
		TreeNode * node1 = NULL;
		TreeNode * node2 = NULL;
		
		if (queue.size() <= 1)
			return;
		
		for (int i = 1; i < queue.size(); ++i)
		{
			TreeNode * prev = queue[i-1];
			TreeNode * curr = queue[i];
			
			if (prev->val > curr->val)
			{
				if (!node1)
					node1 = prev;
				node2 = curr;
			}
		}
		
		swap(node1, node2);
	}
	
	void swap(TreeNode * node1, TreeNode * node2)
	{
		if (!node1 || !node2)
			return;
		
		int temp = node1->val;
		node1->val = node2->val;
		node2->val = temp;
	}
	
	void traverse(TreeNode * root, vector<TreeNode *> &queue)
	{
		if (!root)
			return;
		
		traverse(root->left, queue);
		queue.push_back(root);
		traverse(root->right, queue);
	}
};

#endif
