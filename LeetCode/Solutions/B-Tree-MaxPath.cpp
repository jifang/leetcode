class Solution {
public:
    int maxPathSum(TreeNode *root) {

		return _maxPathSum(root, true);
    }
	
private:
	int _maxPathSum(TreeNode *root, bool firstTime = false) {
        
		if (firstTime)
			longest = INT_MIN;
		
        if (root == NULL)
			return 0;
		
		int value = root->val;
		int left = _maxPathSum(root->left);
		int right = _maxPathSum(root->right);
		
		if (max(left, right) > 0)
			value += max(left, right);
		
		int localMax = root->val;
		localMax += left > 0 ? left : 0;
		localMax += right > 0 ? right : 0;
		
		if (localMax > longest)
			longest = localMax;
		
		if (firstTime)
			return longest;
		else
			return value;
    }
	
	int longest;
};