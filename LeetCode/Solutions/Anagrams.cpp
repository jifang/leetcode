class Solution {
public:
    vector<string> anagrams(vector<string> &inStrs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	
		vector<string> result;
		
  		if (inStrs.size() <= 1)
  			return result;
  		
  		vector<string> strs(inStrs);
  		map<string, vector<string> > map;
		
  		vector<string>::iterator it = strs.begin();
  		vector<string>::iterator originIt = inStrs.begin();
  		while (it != strs.end())
  		{
  			sort((*it).begin(), (*it).end());
  			
  			map[*it].push_back(*originIt);
  			
  			++it;
  			++originIt;
  		}
  		
  		it = strs.begin();
		
  		sort(it, strs.end());
  		vector<string>::iterator prevIt = it;
  		++it;
  		
		bool added = false;
  		while (it != strs.end())
  		{
  			if ((*it).compare(*prevIt) == 0)
			{
				if (!added)
				{
					result.insert(result.end(), map[*it].begin(), map[*it].end());
					added = true;
				}
			}
			else
			{
				added = false;
			}
			
  			prevIt = it;
  			++it;
  		}
  		
  		return result;
    }
};