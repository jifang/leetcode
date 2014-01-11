class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

    	string &shortStr = (a.length() > b.length()) ? b : a;
		string &longStr = (a.length() > b.length()) ? a : b;
		
		string::reverse_iterator shortStrIt = shortStr.rbegin();
		string::reverse_iterator longStrIt = longStr.rbegin();
	
		
		string sum(longStr.length() + 1, '0');
		string::reverse_iterator sumStrIt = sum.rbegin();
		int carry = 0;
		while (longStrIt != longStr.rend())
		{
			int result = carry;
			carry = 0;
			
			if (shortStrIt == shortStr.rend())
			{
				if (*longStrIt == '1')
				{
					if (result)
					{
						carry = 1;
						result = 0;
					}
					else
					{
						result = 1;
					}
				}
			}
			else
			{
				if (*longStrIt == '1' && *shortStrIt == '1')
				{
					carry = 1;
				}
				else if (*longStrIt == '1' || *shortStrIt == '1')
				{
					if (result)
					{
						carry = 1;
						result = 0;
					}
					else
					{
						result = 1;
					}
				}
				++shortStrIt;
			}
			
			if (result)
				*sumStrIt = '1';
			
			++longStrIt;
			++sumStrIt;
		}
		
    	if (carry)
			*sumStrIt = '1';
		else
			sum.erase(0, 1);
		
		return sum;
	}
};
