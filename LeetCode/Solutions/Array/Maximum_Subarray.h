//
//  Maximum_Subarray.h
//  LeetCode
//
//  Created by Fish on 3/9/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Maximum_Subarray_h
#define LeetCode_Maximum_Subarray_h

#include "Tree.h"

/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 */
class Solution {
public:
	RUN
	
    int maxSubArray(int A[], int n)
	{
		if (n == 0)
			return 0;
		
		int prevMax = INT_MIN;
		int currSum = INT_MIN;
		
		for (int i = 0; i < n; ++i)
		{
			if (currSum < 0)
			{
				if (A[i] > currSum)
				{
					currSum = A[i];
				}
			}
			else
			{
				if (A[i] >= 0)
				{
					currSum += A[i];
				}
				else
				{
					if (prevMax < currSum)
						prevMax = currSum;
					
					currSum += A[i];
					
					if (currSum < 0)
						currSum = 0;
				}
			}
		}
		
		return std::max(prevMax, currSum);
    }
};

#endif
