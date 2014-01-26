//
//  Remove_Element.h
//  LeetCode
//
//  Created by Fish on 1/25/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Remove_Element_h
#define LeetCode_Remove_Element_h

class Solution {
public:
	static void run() {}
	
    int removeElement(int A[], int n, int elem)
	{
		int i = 0;
		while (i < n)
		{
			if (A[i] == elem)
				A[i] = A[--n];
			else
				++i;
		}
		
		return n;
    }
};

#endif
