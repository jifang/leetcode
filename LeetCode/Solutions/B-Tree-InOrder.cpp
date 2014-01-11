class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	
		if (root == NULL)
			return vector<int>(0);
		
		//leaf
		if (root->left == NULL && root->right == NULL)
			return vector<int>(1, root->val);
		
		vector<int> leftTree = inorderTraversal(root->left);
		vector<int> rightTree = inorderTraversal(root->right);

		leftTree.insert(leftTree.end(), root->val);
		leftTree.insert(leftTree.end(), rightTree.begin(), rightTree.end());
        
		return leftTree;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	
		if (root == NULL)
			return vector<int>();
		
		vector<int> result;
		stack<TreeNode *> pending;
		pending.push(root);
		
		TreeNode *last = NULL; //Node whose children on the left has been processed
			
		while (!pending.empty())
		{
			TreeNode *node = pending.top();
			pending.pop();
			
			// Children on left has been traversed
			if (node == last)
			{
				if (!pending.empty())
					last = pending.top();
				
				result.push_back(node->val);
				
				if (node->right != NULL)
					pending.push(node->right);
			}
			else
			{
				// Children on Left has not been traversed
				if (node->left == NULL)
				{
					if (!pending.empty())
						last = pending.top();
					
					result.push_back(node->val);
					
					if (node->right != NULL)
						pending.push(node->right);
				}
				else
				{
					pending.push(node);
					pending.push(node->left);
				}
			}
		}
        
		return result;
    }
};
