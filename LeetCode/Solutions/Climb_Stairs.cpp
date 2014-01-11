class Solution {
public:
    inline int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if (n <= 0)
			return 0;
		
		if (n == 1)
			return 1;
		
		if (n == 2)
			return 2;
		
		return climbStairs(n-1) + climbStairs(n-2);
        
    }
};

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if (n <= 0)
			return 0;
		
		if (n == 1)
			return 1;
		
		if (n == 2)
			return 2;
		
		int last = 2;
		int beforeLast = 1;
		int result = 0;
		
		for (int i = 3; i <= n; ++i)
		{
			result = last + beforeLast;
			beforeLast = last;
			last = result;
		}
			
		return result;
    }
};