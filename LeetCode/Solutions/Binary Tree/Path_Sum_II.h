//
//  Path_Sum_II.h
//  LeetCode
//
//  Created by Fish on 1/27/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Path_Sum_II_h
#define LeetCode_Path_Sum_II_h

#include "Tree.h"

class Solution {
public:
	RUN
	
    vector<vector<int> > pathSum(TreeNode *root, int sum)
	{
		vector<vector<int> > empty(0);
        if (!root)
		{
			return empty;
		}
		
		if (!root->left && !root->right)
		{
			if (sum == root->val)
			{
				vector<int> val(1, sum);
				return vector<vector<int> > (1, val);
			}
			else
			{
				return empty;
			}
		}
			
	
		vector<vector<int> > left = pathSum(root->left, sum - root->val);
		vector<vector<int> > right = pathSum(root->right, sum - root->val);
		left.insert(left.end(), right.begin(), right.end());
		for (int i = 0; i < left.size(); ++i)
		{
			left[i].insert(left[i].begin(), root->val);
		}
		
		return left;
		
    }
};
#endif
