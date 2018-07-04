#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		vector<int>::iterator index = unique(nums.begin(), nums.end());
		return distance(nums.begin(), index);
	}
};

int main()
{
	Solution so;
	vector<int> vc{1, 1, 2, 3, 4, 5, 3, 5, 5, 3, 3};
	sort(vc.begin(), vc.end());
	cout << so.removeDuplicates(vc) << endl;


	return 0;
}