#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	//The brute force approach.
	int maxSubArray(vector<int>& nums) {
		//maintain two nums -- correspond to local optimal approach and global optimal approach.
		int ret = nums.front();
		int cur_num = nums.front();

		for (vector<int>::iterator it = nums.begin() + 1; 
				it != nums.end(); ++it) {

			cur_num = max(*it, cur_num + *it);//local optimal solution.
			ret = max(ret, cur_num);//global optimal solution.
		}

		return ret;

		//perfect..
	}
};

int main()
{

	return 0;
}