#include<iostream>

#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		//my best way.
		sort(nums.begin(), nums.end());
		vector<int>::iterator index = unique(nums.begin(), nums.end());
		if (index == nums.end()) {
			//return false;
		}
		else {
			//return true;
		}

		//print the first duplicates element.
		//cout << *index << endl;

		//this print prove the element isn't be delete in unique function.
		/*for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
			cout << *it << endl;
		}*/

		//other more better way.
		return nums.size() != unordered_set<int>(nums.begin(), nums.end()).size();
	}
};

int main()
{
	int arr[] = { 1,2,2,1 };
	vector<int> nums(arr, arr + 4);

	Solution so;
	so.containsDuplicate(nums);

	return 0;
}