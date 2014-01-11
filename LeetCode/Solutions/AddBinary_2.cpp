//
//  main.cpp
//  LeetCode
//
//  Created by Fish on 11/11/12.
//  Copyright (c) 2012 Fish. All rights reserved.
//

#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<int> valueA;
		vector<int> valueB;

		bool validA = intValue(a, valueA);
		bool validB = intValue(b, valueB);
		
		if (!validA && !validB)
			return "";
		
		if (validA && !validB)
			return a;
		
		if (!validA && validB)
			return b;
		
		if (valueA.size() == 1 && valueA[0] == 0)
			return b;
		
		if (valueB.size() == 1 && valueB[0] == 0)
			return a;
		
		
		vector<int> sum;
		
		int sign = 0;
		
		if ((valueA[0] > 0 && valueB[0] > 0) || (valueA[0] < 0 && valueB[0] < 0))
		{
			vector<int> &small = (valueA.size() < valueB.size()) ? valueA : valueB;
			vector<int> &big = (small == valueB) ? valueA : valueB;
			vector<int>::reverse_iterator itSmall = small.rbegin();
			vector<int>::reverse_iterator itBig = big.rbegin();
			
			sum.resize(big.size());
			
			// Same sign
			sign = (valueA[0] > 0) ? 1 : -1;
			if (sign == -1)
			{
				valueA[0] = -valueA[0];
				valueB[0] = -valueB[0];
			}
			
			long i = big.size();
			while (itBig != big.rend())
			{
				if (itSmall == small.rend())
				{
					sum[--i] = *itBig;
				}
				else
				{
					sum[--i] = *itSmall + *itBig;
					++itSmall;
				}
				++itBig;
			}
		}
		else
		{
			int result = this->compare(valueA, valueB);
			
			if (result == 0)
				return "0";
			
			vector<int> &small = (result < 0) ? valueA : valueB;
			vector<int> &big = (result > 0) ? valueA : valueB;
			vector<int>::reverse_iterator itSmall = small.rbegin();
			vector<int>::reverse_iterator itBig = big.rbegin();
			
			sum.resize(big.size());
			sign = big[0] > 0 ? 1 : -1;
			
			big[0] = abs(big[0]);
			small[0] = abs(small[0]);
			
			long i = big.size();
			while (itBig != big.rend())
			{
				if (itSmall == small.rend())
				{
					sum[--i] = *itBig;
				}
				else
				{
					sum[--i] = *itBig - *itSmall;
					++itSmall;
				}
				++itBig;
			}
			
			vector<int>::reverse_iterator itRSum = sum.rbegin();
			bool carry = false;
			while (itRSum != sum.rend())
			{
				if (carry)
					--(*itRSum);
				
				carry = false;
				if (*itRSum < 0)
				{
					*itRSum += 1 << 30;
					carry = true;
				}
				
				++itRSum;
			}
			
			vector<int>::iterator itSum = sum.begin();
			while (itSum != sum.end() && *itSum != 0)
			{
				++itSum;
			}
			
			if (itSum != sum.begin())
				sum.erase(sum.begin(), itSum);
			
			sum[0] *= sign;
		}
		
		this->removeCarry(sum);
		
		return this->toString(sum);
    }
	
	// return 1 if num1 > num2, -1 if num1 < num2, 0 if num1 == num2
	int compare(vector<int> &num1, vector<int> &num2)
	{
		if (num1.size() > num2.size())
			return 1;
		
		if (num1.size() < num2.size())
			return -1;
		
		vector<int>::iterator it1 = num1.begin();
		vector<int>::iterator it2 = num2.begin();
		
		while (it1 != num1.end())
		{
			if (*it1 > *it2)
				return 1;
			if (*it1 < *it2)
				return -1;
			
			++it1;
			++it2;
		}
		
		return 0;
	}
	int length(unsigned int num)
	{
		int lb = 0;
		int ub = 32;
		int pos = (lb + ub) /2;
		
		while (ub - lb > 1)
		{
			if ((num >> pos) > 0)
				lb = pos;
			else
				ub = pos;
			
			pos = (lb + ub) /2;
		}
		
		return ub;
	}
	
	string toString(vector<int> &num)
	{
		int firstSize = this->length(abs(num[0]));

		std::string str;
		if (num[0] < 0)
			str = "-";
		
		str += this->toString(abs(num[0]), firstSize);
		
		vector<int>::iterator numIt = ++num.begin();
		while (numIt != num.end())
		{
			str += this->toString(*numIt, 30);
			++numIt;
		}
		
		return str;
	}
	

	string toString(unsigned num, int length)
	{
		string str(length, '0');
		string::reverse_iterator it = str.rbegin();
		while (num > 0)
		{
			if (num & 1)
				*it = '1';
			++it;
			num = num >> 1;
		}
		
		return str;
	}
	
	// Make sure each int is less than 2^30
	void removeCarry(vector<int> &num)
	{
		vector<int>::reverse_iterator it = num.rbegin();
		bool carry = false;
		
		while (it != num.rend() - 1)
		{
			if (carry)
				++(*it);
			
			carry = false;
			
			if (*it >> 30)
			{
				carry = true;
				*it = (unsigned)*it << 2 >> 2;
			}
			
			++it;
		}
		
		if (carry) ++(*it);
			
	}
	
	bool intValue(string str, vector<int> &num)
	{
		int sign = 1;
		
		if (str.empty())
		{
			num.push_back(0);
			return true;
		}

		int index = 0;
		long length = str.length();
		
		if (str[0] == '-' || str[0] == '+')
		{
			++index;
			--length;
			
			if (str[0] == '-')
				sign = -1;
		}
		
		if (length == 0)
			return false;

		int remainder = length % 30;
		int segment = (length - remainder) / 30;
		int value = 0;
		num.reserve(segment + 1);
		string firststr(str, index, remainder);
		
		if (!firststr.empty())
		{
			if (intValue(firststr, value))
			{
				num.push_back(value);
				index += remainder;
			}
			else
			{
				return false;
			}
		}
		
		for (int i = 0; i < segment; ++i)
		{
			string subStr(str, index, 30);
			if (intValue(subStr, value))
			{
				num.push_back(value);
				index += 30;
			}
			else
			{
				return false;
			}
		}
		
		num[0] *= sign;
		
		return true;
	}
	
	// Parse the binary string into the int, we don't handle the sign
	// String can't be longer than 31 characters
	bool intValue(string &a, int &value)
	{
		value = 0;
		long size = a.length();
		for (long i = size; i > 0; --i)
		{
			char c = a[i-1];
			if (c == '1')
				value += 1 << (size - i);
			else if (c != '0')
				return false;
		}

		return true;
	}
};

int main(int argc, const char * argv[])
{
//	int data[] = {-493,-487,-480,-464,-456,-449,-445,-439,-437,-427,-415,-403,-400,-398,-372,-349,-347,-332,-330,-324,-287,-282,-273,-254,-249,-243,-220,-219,-217,-217,-214,-199,-198,-170,-153,-150,-143,-136,-113,-93,-91,-88,-87,-78,-58,-58,-55,-51,-49,-42,-38,-36,-26,0,13,28,54,61,85,90,90,111,118,136,138,167,170,172,195,198,205,209,241,263,290,302,324,328,347,359,373,390,406,417,435,439,443,446,464,465,468,484,486,492,493};
	
	int data3[] = {-7,-71,-7,-13,45,46,-50,83,-29,-72,9,32,-74,81,68,92,-31,28,-46,-86,-70,31,-62,-20,-56,97,-41,21,81,17,-14,56,69,16,25,-38,65,-48,15,16,-25,68,-41,46,-56,-2,-3,82,8,19,-32,62,92,-56,-9,43,50,100,66,-45,41,-24,-4,83,-36,79,24,97,82,89,-56,-91,75,-64,-68,96,-55,-52,-58,-37,68,27,89,-40,-42,94,-92,-70,40,74,75,-15,54,-54,0,4,-39,93,88,-31,-26,93,8,-85,-62,89,-93,98,4,-58,8,5,-93,7,30,-75,63,41,62,-52,49,93,-11,87,7,52,5,-96,-56,43,-41,-75,-16,73,6,35,-32,62,-50,-57,-25,5,-32,94,-70,6,19,-12,63,-47,76,-57,41,-49,-33,-15,-81,55,88,67,-51,100,-19,-39,62,84,-100,78,-24,31,-32,-83,33,-25,86,9,-30,-40,52,64,-30,-17,19,-69,-89,-67,-79,-100,-53};
	int data2[] = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
	int target = 157;
	
	int data[] = { -1 , 2 , 4 };
	std::vector<int> num(data, data + sizeof(data)/sizeof(int));
	std::vector<int>::iterator it = num.begin();
	

	
	
	Solution test;
	cout << test.addBinary("100100001101100010011100010110000001001111110111010111110100",
						   "111100011011010001100011011000111001011010111101111111010000") << endl;

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

