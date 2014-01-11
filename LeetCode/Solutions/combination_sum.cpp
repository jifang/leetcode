class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		// Map of the sets keyed by their sum
		// i.e. map[3] = { [1,1,1], [3], [2,1] }

		knownCombination.clear();
		sort(candidates.begin(), candidates.end());

		return subCombinationSum(candidates, target);
    }
	
private:
	
	// Map of the sets keyed by their sum
	// i.e. map[3] = { [1,1,1], [3], [2,1] }
	map<int, vector<vector<int> > >knownCombination;

	
	vector<vector<int> > subCombinationSum(vector<int> &candidates, int target)
	{
		
		if (knownCombination.find(target) != knownCombination.end())
			return knownCombination[target];
		
		vector<vector<int> > results;
		
		if (target < candidates[0])
			return vector<vector<int> >();
		
		for (int i = 0; i < candidates.size(); ++i)
		{
			if (candidates[i] > target)
			{
				break;
			}
			
			if (candidates[i] == target)
			{
				results.push_back(vector<int>(1, target));
				break;
			}
			
			vector<vector<int> > subResults = subCombinationSum(candidates, target - candidates[i]);
			if (!subResults.empty())
			{
				vector<vector<int> >::iterator it = subResults.begin();
				while (it != subResults.end())
				{
					vector<int> data = (*it);
					data.push_back(candidates[i]);
					sort(data.begin(), data.end());
					results.push_back(data);
					++it;
				}
			}
		}
		
		vector<vector<int> > uniq_results = removeDuplicates(results);
		knownCombination[target] = uniq_results;
		
		return uniq_results;
    }
	
	vector<vector<int> >  removeDuplicates(vector<vector<int> > &input)
	{
		sort(input.begin(), input.end(), &Solution::compare);
		vector<vector<int> > results;

		if (!input.empty())
		{
			vector<vector<int> >::iterator resultsIt = input.begin();
			vector<vector<int> >::iterator lastResultsIt = input.end();
			
			while (resultsIt != input.end())
			{
				if (lastResultsIt == input.end() || *lastResultsIt != *resultsIt)
					results.push_back(*resultsIt);
				
				lastResultsIt = resultsIt;
				++resultsIt;
			}
		}
		
		return results;
	}
	
	static bool compare (const vector<int> &num1, const vector<int> &num2)
	{
		if (num1.size() != num2.size())
			return (num1.size() < num2.size());
		
		if (sum(num1) != sum(num2))
			return (sum(num1) < sum(num2));
		
		for (int i = 0; i < num1.size(); ++i)
		{
			if (num1[i] != num2[i])
				return (num1[i] < num2[i]);
		}
		
		return false;
	}
	
	static int sum(const vector<int> &num)
	{
		int sum = 0;
		vector<int>::const_iterator it = num.begin();
		while (it != num.end())
		{
			sum += *it;
			++it;
		}
		return sum;
	}
	
	void print (vector<vector<int> > &result)
	{
		vector<vector<int> >::iterator resultIt = result.begin();
		while (resultIt != result.end())
		{
			cout << " === " << endl;
			vector<int>::iterator it = (*resultIt).begin();
			while (it != (*resultIt).end())
			{
				cout << " " << *it << endl;
				++it;
			}
			++resultIt;
		}

	}

};