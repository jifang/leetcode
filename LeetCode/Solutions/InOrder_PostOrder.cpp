class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (inorder.empty())
    		return NULL;
		
		TreeNode *root = new TreeNode( *(postorder.rbegin()) );
		
		if (inorder.size() == 1)
			return root;
		
		//Search the inorder to find the root
		vector<int>::iterator it = inorder.begin();
		while (it != inorder.end())
		{
			if (*it == root->val)
				break;
			++it;
		}
		
		long leftSize = distance(inorder.begin(), it);
		long rightSize = distance(it + 1, inorder.end());
		
		if (leftSize == 0)
		{
			// left is NULL
			vector<int> rightInOrder(inorder.begin() + 1, inorder.end());
			vector<int> rightPostOrder(postorder.begin(), postorder.end() - 1);
			
			root->right = buildTree(rightInOrder, rightPostOrder);
		}
		else if (rightSize == 0)
		{
			// right is NULL
			vector<int> leftInOrder(inorder.begin(), inorder.end() - 1);
			vector<int> leftPostOrder(postorder.begin(), postorder.end() - 1);
			
			root->left = buildTree(leftInOrder, leftPostOrder);
		}
		else
		{
			vector<int> leftInOrder(inorder.begin(), it);
			vector<int> rightInOrder(it + 1, inorder.end());
			
			
			vector<int> leftPostOrder(postorder.begin(), postorder.begin() + leftSize);
			vector<int> rightPostOrder(postorder.end() - 1 - rightSize, postorder.end() - 1);
			
			
			root->right = buildTree(rightInOrder, rightPostOrder);
			root->left = buildTree(leftInOrder, leftPostOrder);
		}
		
		return root;
    }
};