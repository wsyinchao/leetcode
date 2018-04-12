#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

//commit code
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//the return value is usefully and let me expand
		//good algorithm
		std::map<int, int> nums_map;
		for (int i = 0; i < nums.size(); i++) {
			int comp = target - nums[i];

			if (nums_map.find(comp) != nums_map.end())
				return { nums_map[comp], i };
			else
				nums_map[nums[i]] = i;
		}
		return { 0, 0 };
	}
};

int main()
{
	Solution sol;

	vector<int> test{2,7,11,15};
	vector<int> res = sol.twoSum(test, 9);

	for (auto it = res.begin(); it != res.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}