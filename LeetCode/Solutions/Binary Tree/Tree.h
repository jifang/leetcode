//
//  Tree.h
//  LeetCode
//
//  Created by Fish on 1/27/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Tree_h
#define LeetCode_Tree_h

#define RUN 	static void run () {};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif
