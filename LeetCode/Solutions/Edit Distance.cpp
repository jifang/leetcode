class Solution {
public:
    int closest(const string &word1, const string &word2)
	{
		savedResult.clear();
		return this->_closest(word1, word2);
    }
private:
	
    int _closest(const string &word1, const string &word2) {
		
		if (word1 == word2)
			return 0;
		
		if (savedResult.find(make_pair(word1, word2)) != savedResult.end())
			return savedResult[make_pair(word1, word2)];
		
		if (savedResult.find(make_pair(word2, word1)) != savedResult.end())
			return savedResult[make_pair(word2, word1)];

		if (word1.length() == 0 || word2.length() == 0)
			return static_cast<int>(word1.length() + word2.length());
		
		if (word1[0] == word2[0])
			return _closest(word1.substr(1), word2.substr(1));
		
		int result_replace = 1 + _closest(word1.substr(1), word2.substr(1));
		
		int result_add = 1 + _closest(word1.substr(1), word2.substr(0));

		int result_delete = 1 + _closest(word1.substr(0), word2.substr(1));
		
		int distance = min( min(result_replace, result_add), result_delete);
		
		return distance;
    }
	
	static bool sortdescend (pair<int, int> i,pair<int, int> j) { return (i.second > j.second); }
	
	map<pair<const string &, const string &>, int> savedResult;

};