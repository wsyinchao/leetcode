#include<iostream>

#include<vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		//The best way.
		int j = 0;
		for (vector<int>::iterator it = nums.begin();
			it != nums.end();
			++it) {

			if (*it != 0) {
				nums[j++] = *it;
			}
		}

		for (; j < nums.size(); ++j) {
			nums[j] = 0;
		}
	}
};

int main()
{
	vector<int> nums = { 0,1,0,3,12 };

	Solution so;

	so.moveZeroes(nums);

	for (auto item : nums) {
		cout << item << " ";
	}
	cout << endl;

	return 0;
}