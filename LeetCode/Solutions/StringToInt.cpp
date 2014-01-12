#include <iostream>
#include <string>

class Solution {
public:
    int atoi(const char *inStr) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!inStr)
            return 0;
    	
		// Remove empty space
		const char* str = inStr;
		while (*str)
		{
			if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\b')
				++str;
			else
				break;
		}
        
		int length = strlen(str);
		
		if (length <= 0)
			return 0;
		
		int sign = 1;
		const char *pStart = str;
		long long result = 0;
		
        if (str[0] == '+' || str[0] == '-')
		{
			++pStart;
			sign = (str[0] == '+') ? 1 : -1;
		}
		
		while (*pStart)
		{
			if (*pStart < '0' || *pStart > '9')
				break;
			
			result *= 10;
			result += (*pStart - '0');
			
			// overflow
			if (result > INT_MAX)
				return sign > 0 ? INT_MAX : INT_MIN;
			
			++pStart;
			
		}
		
		return (int)result * sign;
	}
};