/*
	You are a professional robber planning to rob houses along a street. 
	Each house has a certain amount of money stashed, the only constraint stopping 
	you from robbing each of them is that adjacent houses have security system connected 
	and it will automatically contact the police if two adjacent houses were broken
	into on the same night.

	Given a list of non-negative integers representing the amount of money of each house, 
	determine the maximum amount of money you can rob tonight without alerting the police.
*/

//dynamic programing....

#include<iostream>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		vector<int> ret;
		int maxNum = 0;
		for (int i = 0; i < len; ++i) {
			if (i == 0) {
				ret.push_back(nums[i]);
			}
			else if(i == 1) { 
				ret.push_back(max(nums[0], nums[1]));
			}
			else {
				ret.push_back(max(nums[i] + ret[i - 2], ret[i - 1]));
			}

			if (ret.back() > maxNum)
				maxNum = ret.back();
		}

		return maxNum;
	}
};

int main()
{
	return 0;
}