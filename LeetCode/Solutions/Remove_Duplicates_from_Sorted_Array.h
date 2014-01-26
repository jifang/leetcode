//
//  Remove_Duplicates_from_Sorted_Array.h
//  LeetCode
//
//  Created by Fish on 1/25/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Remove_Duplicates_from_Sorted_Array_h
#define LeetCode_Remove_Duplicates_from_Sorted_Array_h


class Solution {
public:
	static void run() {
	
		Solution s;
		int a[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 9};
		int n = s.removeDuplicates(a, sizeof(a)/ sizeof(int));
		
		cout << n << endl;
		
		for (int i = 0; i < n; ++i)
			cout << a[i] << endl;
	}
    
	int removeDuplicates(int A[], int n)
	{
		if (n == 0)
			return 0;
		
		int i = 1;
		int j = 1;
        while (i < n)
		{
			if (A[i] <= A[i-1])
			{
				while (j < n)
				{
					if (A[j] > A[i-1])
						break;
					++j;
				}
				
				if (j == n || A[i-1] == A[j])
					break;
				
				swap(A[i], A[j]);
			}
			
			++i;
		}
		
		return i;
    }
	
private:
	void swap (int &x, int &y)
	{
		int t = y;
		y = x;
		x = t;
	}
};

#endif
