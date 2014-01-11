//
//  main.cpp
//  LeetCode
//
//  Created by Ji Fang on 12/21/12.
//  Copyright (c) 2012 Microsoft. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

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

int main(int argc, const char * argv[])
{
	Solution test;
	
	int data[] = {1, 9, 22, 3, 11, 1};

	//int data[] = {3,2,1,6,9,1,2,3,8};
	
//	cout << test.bitNum(63);
	
	std::vector<int> height(data, data + sizeof(data)/sizeof(int));
	
	std::vector<int> result = test.divide(1536923, 13);
	
	cout << result[0] << " " << result[1] << endl;

    return 0;
}

