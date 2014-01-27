//
//  Binary_Tree_Maximum_Path_Sum.h
//  LeetCode
//
//  Created by Fish on 1/26/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Binary_Tree_Maximum_Path_Sum_h
#define LeetCode_Binary_Tree_Maximum_Path_Sum_h

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	static void run () {}
	int maxPathSum(TreeNode * root)
	{
		maxSum = INT_MIN;
		maxSubPathSum(root);
		return maxSum;
	}
	
	
private:
	
	int maxSubPathSum(TreeNode *root)
	{
        if (!root)
			return 0;
		
		int left = maxSubPathSum(root->left);
		int right = maxSubPathSum(root->right);
		
		if (left >= 0 && right >= 0)
		{
			int localMax = left + right + root->val;
			if (localMax > maxSum)
				maxSum = localMax;
		}
		
		int maxSub = std::max(left, right);
		if (maxSub > 0)
		{
			if (maxSub + root->val > maxSum)
				maxSum = maxSub + root->val;
		}
		else if (root->val > maxSum)
		{
			maxSum = root->val;
		}
		
		
		return maxSub > 0 ? maxSub + root->val : root->val;
    }
	
	int maxSum;
};

#endif
