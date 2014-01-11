class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x <= 0)
            return 0;
    	
        int min = 0;
        int max = x;
        int guess = (min + max) / 2;
        double result = 0;
        
        while (max - min > 1)
        {
            guess = (min + max) / 2;
            result = (double)guess * (double)guess;
            
            if (result == x)
                return guess;
			
            if (result > x)
                max = guess;
            else
                min = guess;
			
        }
        
        if (max * max == x)
            return max;
		
        return min;
    }
};