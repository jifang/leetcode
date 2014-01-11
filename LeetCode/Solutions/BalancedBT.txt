class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		travers(root);

		if (!root)
			return true;
		
		if (!root->left && !root->right)
			return true;
		
		if (!root->left)
			return root->right->val <= 1;
		
		if (!root->right)
			return root->left->val <= 1;
		
		
		return isBalanced(root->left) && isBalanced(root->right) && (abs(root->left->val - root->right->val) <= 1);
        
    }
	
private:
	int travers(TreeNode *root) {
		
		if (root == NULL)
			return 0;
		
		// leaf
		if (root->left == NULL && root->right == NULL)
		{
			root->val = 1;
		}
		else
		{
			root->val = max(travers(root->left), travers(root->right)) + 1;
		}
		
		return root->val;
		
	}
};