class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        std::vector<vector<int> > results;
        
        if (num.size() < 3)
            return results;
        
        // Sort the incoming vector
        std::sort(num.begin(), num.end());
        
        std::vector<int>::iterator primaryIt = num.begin();
        
        // Initialize the primaryElment - just make sure it is not equal to the first element
        int primaryElement = (*primaryIt) ? 0 : 1;
        
        // Iterate over the vector and 
        while (primaryIt != num.end())
        {
            if (primaryElement == *primaryIt)
            {
                // No need to waste time on duplicate entry
                ++primaryIt;
                continue;
            }
            
            primaryElement = *primaryIt;
            int sumOfTwo = -1 * primaryElement;
            
            // Iterate over the rest of the vector, trying to find the sum of two
            std::vector<int>::iterator secondaryIt = ++primaryIt;
            int seconedElement = (*secondaryIt) ? 0 : 1;
            
            
            while (secondaryIt != num.end())
            {
                // Now try to find the third element
                
                // No need to waste on the duplicate entry
                if (seconedElement == *secondaryIt)
                {
                    ++secondaryIt;
                    continue;
                }
                
                seconedElement = *secondaryIt;
                int queryValue = sumOfTwo - seconedElement;
                
                // Binary search should be sufficient
                std::vector<int>::iterator previousIt = secondaryIt;
                std::vector<int>::iterator lowerBoundIt = secondaryIt++;
                std::vector<int>::iterator upperBoundIt = num.end();
                std::vector<int>::iterator thirdIt = lowerBoundIt;
                
                thirdIt += (upperBoundIt - lowerBoundIt) / 2;
                                
                while (previousIt != thirdIt && thirdIt != num.end())
                {
                    previousIt = thirdIt;
                    
                    if (*thirdIt == queryValue)
                    {
                        // Found!
                        std::vector<int> result;
                        result.push_back(primaryElement);
                        result.push_back(seconedElement);
                        result.push_back(*thirdIt);
                        
                        results.push_back(result);
                        break;        
                    }
                                        
                    if (*thirdIt < queryValue)
                    {
                        lowerBoundIt = thirdIt;
                        thirdIt += (upperBoundIt - lowerBoundIt) / 2;
                    }
                    else
                    {
                        upperBoundIt = thirdIt;
                        thirdIt -= (upperBoundIt - lowerBoundIt) / 2;
                    }
                }
            }
        }
        
        return results;
    }
};