//
//  Divide_Two_Integers.h
//  LeetCode
//
//  Created by Fish on 1/25/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Divide_Two_Integers_h
#define LeetCode_Divide_Two_Integers_h

class Solution {
public:
	static void run() {
		Solution s;
		cout << s.divide(INT_MIN, 1) << endl;
	}
    int divide(int dividend, int divisor)
	{
		if (divisor == 0)
			return INT_MAX;
		if (dividend == 0)
			return 0;
		
		bool sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);

		long long newdividend = llabs(dividend);
		long long newdivisor = llabs(divisor);
		
		int quotient = 0;
		
		while (newdividend >= newdivisor)
		{
			long long half = newdividend;
			int shift = 0;
			
			while (true)
			{
				if (half >> 1 > newdivisor)
				{
					half >>= 1;
					++shift;
				}
				else
				{
					quotient += 1 << shift;
					newdividend -= (newdivisor << shift);
					break;
				}
			}
			
		}

		
		return sign ? quotient : (0 - quotient);
    }
	
};

#endif
