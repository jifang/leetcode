class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
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
		vector<vector<TreeNode *> >::iterator levelIt = nodesByLevel.begin();
		bool forward = true;
		
		while (levelIt != nodesByLevel.end())
		{
			vector<int> resultByLevel;
			resultByLevel.reserve((*levelIt).size());
			
			if (forward)
			{
				vector<TreeNode *>::iterator nodeIt = (*levelIt).begin();
				while (nodeIt != (*levelIt).end())
				{
					resultByLevel.push_back((*nodeIt)->val);
					++nodeIt;
				}
			}
			else
			{
				vector<TreeNode *>::reverse_iterator nodeIt = (*levelIt).rbegin();
				while (nodeIt != (*levelIt).rend())
				{
					resultByLevel.push_back((*nodeIt)->val);
					++nodeIt;
				}
			}
			
			forward = !forward;
			results.push_back(resultByLevel);
			++levelIt;
		}
		
		return results;
    }
};
