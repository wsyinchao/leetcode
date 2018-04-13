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
		map<int, int> map_nums;
		for (int i = 0; i < nums.size(); ++i)
		{
			int diff = target - nums[i];
			if (map_nums.find(diff) != map_nums.end())
			{
				return { map_nums[diff], i };
			}
			else
			{
				map_nums[nums[i]] = i;
			}
		}
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