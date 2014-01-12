//
//  SingleNumber.h
//  LeetCode
//
//  Created by Fish on 1/11/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef __LeetCode__SingleNumber__
#define __LeetCode__SingleNumber__

#include <iostream>

class Solution {
public:
	static void run ()
	{
		Solution s;
		int test[] = {1, 2, 1, 5, 5};
		std::cout << s.singleNumber(test, sizeof(test)/sizeof(int)) << std::endl;
	}
	
    int singleNumber(int A[], int n) {
		int result = 0;
		for (int i = 0; i < n; ++i)
			result ^= A[i];
		return result;
    }
};


#endif /* defined(__LeetCode__SingleNumber__) */
