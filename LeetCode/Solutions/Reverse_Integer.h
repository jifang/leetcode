//
//  Reverse_Integer.h
//  LeetCode
//
//  Created by Fish on 1/12/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Reverse_Integer__h
#define LeetCode_Reverse_Integer__h

class Solution {
public:
	static void run () {
		Solution s;
		cout << s.reverse(0) << endl;
	}
	
    int reverse(int x) {
		
		int sign = (x > 0) ? 1 : -1;
		x = abs(x);
		
		int result = 0;
        do {
			result *= 10;
			result += x % 10;
			x /= 10;
		} while (x);
		
		return result * sign;
    }
};

#endif
