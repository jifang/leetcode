//
//  main.cpp
//  LeetCode
//
//  Created by Ji Fang on 12/21/12.
//  Copyright (c) 2012 Microsoft. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

#include "Remove_Duplicates_from_Sorted_Array_II.h"


void printVector(vector<int> &s) {
	cout << "Vector:[ ";
	for (int i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << "]" << endl;
}

int main(int argc, const char * argv[])
{
	Solution::run();

    return 0;
}

