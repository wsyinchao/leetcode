#include <iostream>

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int diff = 0;
		unordered_map<int, int>map;//¸ßÐ§ÈÝÆ÷...

		for (int i = 0; i < nums.size(); ++i) {
			diff = target - nums[i];

			if (map.find(diff) != map.end()) {
				return { map[diff], i };
			}
			else {
				map[nums[i]] = i;
			}
		}
	}
};

int main()
{
	Solution so;

	vector<int> nums = { 3,2,4 };
	vector<int> ret = so.twoSum(nums, 6);

	for (auto item : ret) {
		cout << item << " ";
	}
	cout << endl;

	return 0;
}
