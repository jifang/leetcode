//
//  Valid_Parentheses.h
//  LeetCode
//
//  Created by Fish on 1/25/14.
//  Copyright (c) 2014 Microsoft. All rights reserved.
//

#ifndef LeetCode_Valid_Parentheses_h
#define LeetCode_Valid_Parentheses_h

class Solution {
public:
	
	static void run() {}
    bool isValid(string s)
	{
		stack<char> parentheses;
		
		for (int i=0; i< s.length(); ++i)
		{
			if (left(s[i]))
			{
				parentheses.push(s[i]);
			}
			else if (right(s[i]))
			{
				if (parentheses.empty() || !match(parentheses.top(), s[i]))
					return false;

				parentheses.pop();
			}
		}
		return parentheses.empty();
	}
	
private:
	bool left(char &a)
	{
		return (a == '(' || a == '[' || a == '{');
	}
	
	bool right(char &a)
	{
		return (a == ')' || a == ']' || a == '}');
	}
				
	bool match(char &a, char &b)
	{
		if (a == '(')
			return b == ')';
		if (a == ')')
			return b == '(';
		if (a == '[')
			return b == ']';
		if (a == ']')
			return b == '[';
		if (a == '{')
			return b == '}';
		if (a == '}')
			return b == '{';
		
		return false;
	}
};

#endif
