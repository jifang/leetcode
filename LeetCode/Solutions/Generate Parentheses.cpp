class Solution {
public:
    vector<string> generateParenthesis(int n)
	{
		savedResult.clear();
		
		return generate(n, n);
	
    }
private:
	
	vector<string> generate(int left, int right)
	{
		if (left == 0 && right == 0)
			return vector<string>();
		
		if (left == 0)
			return vector<string>(1, string(right, ')'));
		
		if (savedResult.find(make_pair(left, right)) != savedResult.end())
			return savedResult[make_pair(left, right)];
		
		// start with (
		vector<string> result = generate(left - 1, right);
		vector<string>::iterator it = result.begin();
		while (it != result.end()) {
			*it = "(" + *it;
			++it;
		}

		if (right > left)
		{
			// start with )
			vector<string> result_leadingRight = generate(left, right - 1);
			if (!result_leadingRight.empty())
			{
				vector<string>::iterator it = result_leadingRight.begin();
				while (it != result_leadingRight.end()) {
					*it = ")" + *it;
					++it;
				}
				
				result.insert(result.end(), result_leadingRight.begin(), result_leadingRight.end());
			}
			
		}
		
		savedResult[make_pair(left, right)] = result;
		
		return result;
	}
	
	map<pair<int, int>, vector<string> > savedResult;
};
