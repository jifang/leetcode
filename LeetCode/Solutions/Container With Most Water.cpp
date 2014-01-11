class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if (height.size() <= 1)
			return 0;
		
		// Sort the incoming vector but keep the origin index.
		vector<pair<int, int> > data;
		data.reserve(height.size());
		
		for (int i = 0; i < height.size(); ++i)
		{
			data.push_back(make_pair(i, height[i]));
		}
		
		// in reverse order
		sort(data.begin(), data.end(), &Solution::sortdescend);
		
		int min = data[0].first;
		int max = data[0].first;
		
		int maxArea = 0;
		
		for (int i = 1; i < data.size(); ++i)
		{
			if (data[i].first < min)
				min = data[i].first;
			
			if (data[i].first > max)
				max = data[i].first;
			
			int area = data[i].second * (max - min);
			if (area > maxArea)
				maxArea = area;
		}
		
		return maxArea;
    }
private:
	static bool sortdescend (pair<int, int> i,pair<int, int> j) { return (i.second > j.second); }

};