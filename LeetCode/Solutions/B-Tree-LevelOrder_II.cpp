class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if (!root)
			return vector<vector<int> >();
		
		vector<TreeNode *> rootlevel(1, root);
		vector<vector<TreeNode *> > nodesByLevel(1, rootlevel);
		vector<vector<TreeNode *> >::reverse_iterator lastLevel = nodesByLevel.rbegin();
		
		while (true)
		{
			vector<TreeNode *> level;
			level.reserve((*lastLevel).size() * 2);
			
			vector<TreeNode *>::iterator nodeIt = (*lastLevel).begin();
			while (nodeIt != (*lastLevel).end())
			{
				TreeNode *node = *nodeIt;
				if (node->left)
					level.push_back(node->left);
				if (node->right)
					level.push_back(node->right);
				
				++nodeIt;
			}
			
			if (level.empty())
				break;
			
			nodesByLevel.push_back(level);
			lastLevel = nodesByLevel.rbegin();
		}
		
		vector<vector<int> > results;
		vector<vector<TreeNode *> >::reverse_iterator levelIt = nodesByLevel.rbegin();
		while (levelIt != nodesByLevel.rend())
		{
			vector<int> resultByLevel;
			resultByLevel.reserve((*levelIt).size());
			
			vector<TreeNode *>::iterator nodeIt = (*levelIt).begin();
			while (nodeIt != (*levelIt).end())
			{
				resultByLevel.push_back((*nodeIt)->val);
				++nodeIt;
			}
			
			results.push_back(resultByLevel);
			++levelIt;
		}
		
		return results;
    }
};
