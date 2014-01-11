class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int size = prices.size();
        if (size <= 1)
            return 0;
            
        // Max Profit between 1->n
        vector<int> profit_forward;
        vector<int> profit_reverse;
        
        profit_forward.reserve(size);
        profit_reverse.reserve(size);
        
        
        int min = prices[0];
        int max = prices[0];
        int profit = 0;
        
        for (int i = 0; i < size; ++i)
        {
            if (prices[i] > max)
            {
                max = prices[i];
                
                if (max - min > profit)
                    profit = max - min;
            }
            else if (prices[i] < min)
            {
                if ((max - min) > profit)
                    profit = max - min;
                    
                min = prices[i];
                max = prices[i];
            }
            
			profit_forward[i] = profit;
        }
        
        min = prices[size-1];
        max = prices[size-1];
        profit = 0;
        for (int i = size-1; i >= 0; --i)
        {
        	if (prices[i] < min)
        	{
        		min = prices[i];
        		
        		if (max - min > profit)
        			profit = max - min;
        	}
        	else if (prices[i] > max)
        	{
        		if (max - min > profit)
        			profit = max - min;
        			
        		min = prices[i];
                max = prices[i];
        	}
			
			profit_reverse[i] = profit;
        }
        
        profit = 0;
        
        for (int i = 0; i < size; ++i)
		{
			if (profit_forward[i] + profit_reverse[i] > profit)
				profit = profit_forward[i] + profit_reverse[i];
		}        
        
        return profit;
    }
};