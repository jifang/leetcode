//
//  main.cpp
//  LeetCode
//
//  Created by Fish on 11/11/12.
//  Copyright (c) 2012 Fish. All rights reserved.
//

#include <iostream>

#include <vector>
#include <map>

#define TEST 0

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int closest = 0;
		if (num.size() < 3)
		{
			vector<int>::iterator it = num.begin();
			while (it != num.end())
			{
				closest += *it;
				++it;
			}
			return closest;
		}
		
		sort(num.begin(), num.end());
		
		long size = num.size();
		closest = num[0] + num[1] + num[2];
		for (int i = 0; i < size; ++i)
		{
			for (int j = i + 1; j < size; ++j)
			{
				int sum = num[i] + num[j];
				
				vector<int>::iterator closestIt = findCloset(num, target - sum);
				long index = distance(num.begin(), closestIt);
				
				
				//cout << "Find " << target - sum << "Found " << num[index] << "@" << index << endl;
 				
				if (index == i || index == j)
				{
					if (index == i-1 || index == j-1)
					{
						//candidate is index+2 or index-1
						sum += findCloser(num, target - sum, index - 1, index + 2);
					}
					else if (index == i+1 || index == j+1)
					{
						//candidate is index-2 or index+1
						sum += findCloser(num, target - sum, index - 2, index + 1);
					}
					else
					{
						//candidate is index+1 or index-1
						sum += findCloser(num, target - sum, index - 1, index + 1);
					}
				}
				else
				{
					sum += num[index];
				}
				
				if (abs(target - sum) < abs(target - closest))
					closest = sum;
			}
		}
		
		return closest;
    }

private:

	inline int findCloser (vector<int> &num, int target, int idx1, int idx2)
	{
		if (idx1 < 0 || idx1 >= num.size())
			return num[idx2];
		else if (idx2 < 0 || idx2 >= num.size())
			return num[idx1];
		else
			return (abs(target - num[idx1]) < abs(target - num[idx2])) ? num[idx1] : num[idx2];
	}
	
	vector<int>::iterator findCloset(vector<int> &num, int target) {

		sort(num.begin(), num.end());
		
		vector<int>::iterator lowerBoundIter = num.begin();
		vector<int>::iterator upperBoundIter = num.end() - 1;
		
		while (true)
		{
			
			int minDiff = *lowerBoundIter - target;
			int maxDiff = *upperBoundIter - target;
			
			if (minDiff >= 0)
				return lowerBoundIter;
			if (maxDiff <= 0)
				return upperBoundIter;
			
			vector<int>::iterator targetIter = lowerBoundIter + (upperBoundIter - lowerBoundIter) / 2;

			if (targetIter == lowerBoundIter || targetIter == upperBoundIter)
				return abs(minDiff) <= abs(maxDiff) ? lowerBoundIter : upperBoundIter;
			
			if (*targetIter - target > 0)
				upperBoundIter = targetIter;
			else if (*targetIter - target < 0)
				lowerBoundIter = targetIter;
			else
				return targetIter;
				
		}
	}
	

};

int main(int argc, const char * argv[])
{
//	int data[] = {-493,-487,-480,-464,-456,-449,-445,-439,-437,-427,-415,-403,-400,-398,-372,-349,-347,-332,-330,-324,-287,-282,-273,-254,-249,-243,-220,-219,-217,-217,-214,-199,-198,-170,-153,-150,-143,-136,-113,-93,-91,-88,-87,-78,-58,-58,-55,-51,-49,-42,-38,-36,-26,0,13,28,54,61,85,90,90,111,118,136,138,167,170,172,195,198,205,209,241,263,290,302,324,328,347,359,373,390,406,417,435,439,443,446,464,465,468,484,486,492,493};
	
	int data[] = {-3,-2,-1,0,0,1,2,3, 8};
	int data2[] = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
	int target = 7;
	
	std::vector<int> num(data, data + sizeof(data)/sizeof(int));
	
	Solution test;
	
	int result = test.threeSumClosest(num, target);
	
	cout << result << endl;
//	std::vector<std::vector<int> >::iterator it = results.begin();
//	
//	while (it != results.end())
//	{
//		std::vector<int>::iterator dataIt = (*it).begin();
//		
//		std::cout << "[";
//		while (dataIt != (*it).end()) {
//			std::cout << *dataIt << ", ";
//			++dataIt;
//		}
//		std::cout << "]" << std::endl;
//		++it;
//	}
	
    return 0;
}

