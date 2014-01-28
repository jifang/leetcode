//
//  Binary_Tree_Level_Order_Traversal.h
//  && Binary_Tree_Level_Order_Traversal_II
//	&& Binary_Tree_Zigzag_Level_Order_Traversal
//
//  Looks like iterator is faster than []
//  LeetCode
//
//  Created by Fish on 1/28/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Binary_Tree_Level_Order_Traversal_h
#define LeetCode_Binary_Tree_Level_Order_Traversal_h

#include "Tree.h"

class Solution {
public:
	RUN
	
    vector<vector<int> > levelOrder(TreeNode *root)
	{
        vector<vector<int> > result(0);
		if (!root)
			return result;
		
		vector<TreeNode *> list(0);
		list.push_back(root);
		
		while (!list.empty())
		{
			vector<TreeNode *> newlist(0);
			vector<int> row(0);
			for (int i = 0; i < list.size(); ++i)
			{
				row.push_back(list[i]->val);
				if (list[i]->left)
					newlist.push_back(list[i]->left);
				if (list[i]->right)
					newlist.push_back(list[i]->right);
			}
			result.push_back(row);
			list = newlist;
		}
		
		return result;
    }
	
	vector<vector<int> > levelOrderBottom(TreeNode *root)
	{
		vector<vector<int> > result(0);
		if (!root)
			return result;
		
		vector<TreeNode *> list(0);
		list.push_back(root);
		
		while (!list.empty())
		{
			vector<TreeNode *> newlist(0);
			vector<int> row(0);
			for (int i = 0; i < list.size(); ++i)
			{
				row.push_back(list[i]->val);
				if (list[i]->left)
					newlist.push_back(list[i]->left);
				if (list[i]->right)
					newlist.push_back(list[i]->right);
			}
			result.insert(result.begin(), row);
			list = newlist;
		}
		
		return result;
	}
	
	vector<vector<int> > zigzagLevelOrder(TreeNode *root)
	{
		vector<vector<int> > result(0);
		if (!root)
			return result;
		
		vector<TreeNode *> list(0);
		list.push_back(root);
		bool reverse = false;
		
		while (!list.empty())
		{
			vector<TreeNode *> newlist(0);
			vector<int> row(0);
			for (int i = 0; i < list.size(); ++i)
			{
				if (reverse)
					row.insert(row.begin(), list[i]->val);
				else
					row.push_back(list[i]->val);
				
				if (list[i]->left)
					newlist.push_back(list[i]->left);
				if (list[i]->right)
					newlist.push_back(list[i]->right);
			}
			result.push_back(row);
			list = newlist;
			reverse = !reverse;
		}
		
		return result;
	}
};

#endif
