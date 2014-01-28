//
//  Sum_Root_to_Leaf_Numbers.h
//  LeetCode
//
//  Created by Fish on 1/27/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Sum_Root_to_Leaf_Numbers_h
#define LeetCode_Sum_Root_to_Leaf_Numbers_h

#include "Tree.h"

class Solution {
public:
	
	RUN
	
    int sumNumbers(TreeNode *root)
	{
		if (!root)
			return 0;

		int sum = 0;
		vector<int> result = sumNumbers(root, 0);
		for (int i = 0; i < result.size(); ++i)
		{
			sum += result[i];
		}
		return sum;
    }
	
private:
	vector<int> sumNumbers(TreeNode *root, int parent)
	{
		if (!root)
			return vector<int>(0);
		
		if (!root->left && !root->right)
			return vector<int>(1, parent * 10 + root->val);
		
		vector<int> left = sumNumbers(root->left, parent * 10 + root->val);
		vector<int> right = sumNumbers(root->right, parent * 10 + root->val);
		
		left.insert(left.end(), right.begin(), right.end());

		return left;
	}
};

#endif
