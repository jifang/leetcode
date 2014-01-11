class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (prices.size() <= 1)
            return 0;
            
        vector<int>::iterator it = prices.begin();
        int min = *it;
        int last = *it;
        int profit = 0;
        
        while (it != prices.end())
        {
            if (*it < last)
            {
                profit += (last - min);
                    
                min = *it;
            }

            
            last = *it;
            ++it;
        }
        
        profit += (last - min);
        
        return profit;
    }
};