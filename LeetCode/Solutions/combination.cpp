class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if (n < 0 || k < 0 || n < k)
			return vector<vector<int> >();
		
		int size = 1;
		int j = 1;
		
		for (int i = n-k+1; i <= n; ++i)
		{
			size *= i;
			size /= j++;
		}
		for (; j <= k; ++j)
		{
			size /= j;
		}
		
		vector<vector<int> > result(size, vector<int>(k, 0));

		
		for (int i = 0; i < k; ++i)
		{
			result[0][i] = i + 1;
		}
		
		for (int i = 1; i < size; ++i)
		{
			result[i] = increment(result[i-1], n);
		}
		
		return result;
    }
	
private:
	vector<int> increment(const vector<int> &input, int max)
	{
		vector<int> output = input;
		
		long i = input.size() - 1;
		int pivot = 0;
		for ( ; i >= 0; --i)
		{
			if (output[i] < (max - input.size() + i + 1 ))
			{
				pivot = ++output[i];
				++i;
				break;
			}
		}

		for (; i < input.size(); ++i)
		{
			output[i] = ++pivot;
		}
		
		return output;
	}
};