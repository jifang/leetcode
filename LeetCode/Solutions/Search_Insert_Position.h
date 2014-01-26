//
//  Search_Insert_Position.h
//  LeetCode
//
//  Created by Fish on 1/25/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef Search_Insert_Position_h
#define Search_Insert_Position_h


class Solution {
public:
	
	void static run () {}
	
    int searchInsert(int A[], int n, int target) {
		int lB = 0;
		int hB = n - 1;
		
		while (hB - lB > 1)
		{
			int idx = (hB + lB) / 2;
			if (A[idx] == target)
				return idx;
			else if (A[idx] > target)
				hB = idx;
			else if (A[idx] < target)
				lB = idx;
		}
		
		if (target <= A[lB])
			return lB;
		if (target > A[hB])
			return hB + 1;
		else
			return hB;
		
    }
};

#endif
