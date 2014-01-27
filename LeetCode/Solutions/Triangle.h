//
//  Triangle.h
//  LeetCode
//
//  Created by Fish on 1/27/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Triangle_h
#define LeetCode_Triangle_h

class Solution {
public:
	static void run () {
	
		int myints[] = {1};
		int myints2[] = {1, 2};
		
		std::vector<int> first (myints, myints + sizeof(myints) / sizeof(int) );
		std::vector<int> second (myints2, myints2 + sizeof(myints2) / sizeof(int));
		
		std::vector<vector<int> > triangle(0);
		triangle.push_back(first);
		triangle.push_back(second);
		
		Solution s;
		cout << s.minimumTotal(triangle) << endl;
		
	}
	
    int minimumTotal(vector<vector<int> > &triangle) {

		int rowSize = (int)triangle.size();
		
		if (rowSize == 0)
			return 0;
		
		if (rowSize == 1)
			return minimum(triangle[0]);
		
		vector<int> minimalRow(triangle[rowSize - 1]);
		
		for (int rowIdx = rowSize - 2; rowIdx >= 0; --rowIdx)
		{
			vector<int> row = triangle[rowIdx];
			for (size_t col = 0; col < row.size(); ++col)
			{
				minimalRow[col] = min(row[col] + minimalRow[col], row[col] + minimalRow[col + 1]);
			}
		}
		
		return minimalRow[0];
    }
	
private:
	int minimum(vector<int> row)
	{
		if (row.size() == 0)
			return 0;
		int min = row[0];
		for (int i = 1; i < row.size(); ++i)
		{
			if (row[i] < min)
				min = row[i];
		}
		return min;
	}
};

#endif
