class Solution {
public:
	bool verify(int m, int n)
	{
		return ((m ^ n) == 1 || (m ^ n) % 2 == 0);
		
	}
	
	vector<int> divide(int m, int n)
	{
		vector<int> result(2);

		int remainder = m;
		int div = 0;
		int bitsOfn = bitNum(n);
		
		while (remainder >= n)
		{
			unsigned int guess = bitNum(remainder) - bitsOfn;
			if (remainder >> guess < n)
				--guess;
			
			remainder -= (n << guess);
			div += 1 << guess;
		}
		
		result[0] = div;
		result[1] = remainder;
		
		return result;
			
	}
	
private:
	// return the number of bits for interger
	// e.g. 5 (101) returns 3
	int bitNum(int n)
	{
		int ub = 32;
		int lb = 0;
		
		while (ub - lb > 1)
		{
			int guess = (ub + lb) / 2;
			if ((n >> guess) > 0)
				lb = guess;
			else
				ub = guess;
		}
		
		return ub;
	}
};
