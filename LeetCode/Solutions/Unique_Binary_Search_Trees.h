//
//  Unique_Binary_Search_Trees.h
//  LeetCode
//
//  Created by Fish on 1/12/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Unique_Binary_Search_Trees_h
#define LeetCode_Unique_Binary_Search_Trees_h

class Solution {
public:
	
	static void run() {
		Solution s;
		cout << s.numTrees(13) << endl;
	}
	
    int numTrees(int n) {
        if (n <= 1)
			return n;
		
		if (result[n] > 0)
			return result[n];
		
		int total = 0;
		
		for (int i = 0; i < n; ++i)
		{
			int left = numTrees(i);
			int right = numTrees(n - i - 1);
			if (left == 0 || right == 0)
			{
				total += (left + right);
			}
			else
			{
				total += left * right;
			}
		}
		
		result[n] = total;
		return total;
    }
	
private:
	std::map<int, int> result;
};

#endif
