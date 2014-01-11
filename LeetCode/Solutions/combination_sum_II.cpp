class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		// Map of the sets keyed by their sum
		// i.e. map[3] = { [1,1,1], [3], [2,1] }

		knownCombination.clear();
		sort(candidates.begin(), candidates.end());

		vector<vector<int> > uniq_results = subCombinationSum(candidates, target);
		vector<vector<int> > valid_results = validateResult(uniq_results, candidates);
		
		return valid_results;
    }
	
//private:
	
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
		vector<vector<int> > valid_results = validateResult(uniq_results, candidates);
		
		if (!valid_results.empty())
			knownCombination[target] = valid_results;
		
		
		return valid_results;
    }
	
	vector<vector<int> >  validateResult(vector<vector<int> > &input, const vector<int> &candidates)
	{
		vector<vector<int> > results;
		vector<vector<int> >::const_iterator it = input.begin();
		while (it != input.end())
		{
			if (subset(*it, candidates))
				results.push_back(*it);
			
			++it;
		}
		
		return results;
	}

	
	// returns true if num1 is subset of num2
	bool subset(const vector<int> &num1, const vector<int> &num2)
	{
		vector<int>::const_iterator it = num1.begin();
		vector<int>::const_iterator pos = num2.begin();
		while (it != num1.end())
		{
			vector<int>::const_iterator resultIt = binarySearch(num2, pos, *it);

			if (resultIt == num2.end())
				return false;
			
			pos = resultIt+1;
			++it;
		}
		
		return true;
	}
	
	vector<int>::const_iterator binarySearch(const vector<int> &input, vector<int>::const_iterator pos, int target)
	{
		if (input.empty() || pos == input.end())
			return input.end();
		
		vector<int>::const_iterator lb = pos;
		vector<int>::const_iterator ub = input.end();
		vector<int>::const_iterator it;
		vector<int>::const_iterator resultIt = input.end();
		
		while (ub > lb)
		{
			it = lb + (ub - lb) / 2;
			if (*it == target)
				resultIt = it;
			
			// Not found
			if ((ub - lb) == 1)
			{
				if (ub != input.end() && *ub == target)
					resultIt = ub;
				if (*lb == target)
					resultIt = lb;
				break;
			}
			
			if (*it > target)
				ub = it;
			else 
				lb = it;
		}
		
		if (resultIt != input.end())
		{
			while (resultIt > pos && *(resultIt - 1) == target)
				--resultIt;
		}
		return resultIt;
	}
	
	vector<vector<int> >  removeDuplicates(vector<vector<int> > &input)
	{
		sort(input.begin(), input.end(), &Solution::compare);
		vector<vector<int> > results;

		if (!input.empty())
		{
			vector<vector<int> >::iterator resultsIt = input.begin();
			vector<vector<int> >::iterator lastResultsIt = resultsIt;
			
			results.push_back(*resultsIt);
			
			++resultsIt;

			while (resultsIt != input.end())
			{
				if (*lastResultsIt != *resultsIt)
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
	
	void print (vector<int> &result)
	{
		vector<int>::iterator resultIt = result.begin();
		cout << " === " << endl;
		
		while (resultIt != result.end())
		{
			cout << " " << *resultIt << endl;
			++resultIt;
		}
	}

};