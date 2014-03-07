//
//  Unique_Binary_Search_Trees_II.h
//  LeetCode
//
//  Created by Fish on 3/6/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Unique_Binary_Search_Trees_II_h
#define LeetCode_Unique_Binary_Search_Trees_II_h

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
		vector<TreeNode *> result = s.generateTrees(3);
		cout << result.size() << endl;
	}
    vector<TreeNode *> generateTrees(int n)
	{
		vector<int> numbers(0);
		numbers.reserve(n);
		for (int i = 1; i <=n; ++i)
			numbers.push_back(i);
		
		return generateTrees(numbers);
    }
	
private:
	vector<TreeNode *> generateTrees(vector<int> &numbers)
	{
		vector<TreeNode *> result(0);

		if (numbers.empty())
		{
			result.push_back(NULL);
			return result;
		}
		
		if (numbers.size() == 1)
		{
			result.push_back(new TreeNode(numbers[0]));
			return result;
		}
		
		if (this->patterns.find(numbers.size()) != this->patterns.end())
		{
			return fillPattern(numbers);
		}
		
		vector<int>::iterator it = numbers.begin();
		while (it != numbers.end())
		{
			vector<TreeNode *> left(0);
			vector<TreeNode *> right(0);
			
			if (it != numbers.begin())
			{
				vector<int> leftTree(numbers.begin(), it);
				left = this->generateTrees(leftTree);
			}
			if (it != numbers.end() - 1)
			{
				vector<int> rightTree(it+1, numbers.end());
				right = this->generateTrees(rightTree);
			}
			
			if (left.empty())
			{
				vector<TreeNode *>::const_iterator rightIt = right.begin();
				while (rightIt != right.end()) {
					TreeNode * root = new TreeNode(*it);
					root->right = *rightIt;
					result.push_back(root);
					++rightIt;
				}
			}
			else if (right.empty())
			{
				vector<TreeNode *>::const_iterator leftIt = left.begin();
				while (leftIt != left.end()) {
					TreeNode * root = new TreeNode(*it);
					root->left = *leftIt;
					result.push_back(root);
					++leftIt;
				}
			}
			else
			{
				vector<TreeNode *>::const_iterator leftIt = left.begin();
				while (leftIt != left.end()) {
					
					vector<TreeNode *>::const_iterator rightIt = right.begin();
					while (rightIt != right.end()) {
						TreeNode * root = new TreeNode(*it);
						root->left = *leftIt;
						root->right = *rightIt;
						result.push_back(root);
						++rightIt;
					}
					
					++leftIt;
				}
			}
			
			++it;
		}
		
		this->patterns[numbers.size()] = result;
		return result;
    }
	
	vector<TreeNode *> fillPattern(vector<int> &numbers)
	{
		vector<TreeNode *> pattern = this->patterns[numbers.size()];
		vector<TreeNode *> result(0);
		result.reserve(pattern.size());
		
		vector<TreeNode *>::iterator it = pattern.begin();
		vector<TreeNode *> inorderQueue(0);
		inorderQueue.reserve(numbers.size());
		
		while (it != pattern.end())
		{
			inorderQueue.clear();
			TreeNode * root = this->cloneTree(*it);
			inorderTraverse(root, inorderQueue);
			
			for (int i = 0; i < numbers.size(); ++i)
			{
				inorderQueue[i]->val = numbers[i];
			}
			
			result.push_back(root);
			++it;
		}
		
		return result;
	}
	
	TreeNode * cloneTree(TreeNode * root)
	{
		if (!root)
			return NULL;
		
		TreeNode * newRoot = new TreeNode(root->val);
		newRoot->left = this->cloneTree(root->left);
		newRoot->right = this->cloneTree(root->right);
		
		return newRoot;
	}
	
	void inorderTraverse(TreeNode * root, vector<TreeNode *> &result)
	{
		if (!root)
			return;
		
		inorderTraverse(root->left, result);
		result.push_back(root);
		inorderTraverse(root->right, result);
	}
	
private:
	
	std::map<unsigned long, vector<TreeNode *> > patterns;
};

#endif
