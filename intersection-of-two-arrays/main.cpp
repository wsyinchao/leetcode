#include<iostream>

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		vector<int> intersection;

		set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(intersection));
		//nums1.erase(set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums1.begin()), nums1.end());

		return intersection;

		//another way
		/*unordered_map<int, int> ctr;
		for (int i : a)
		ctr[i]++;
		vector<int> out;
		for (int i : b)
		if (ctr[i]-- > 0)
		out.push_back(i);
		return out;*/
	}
};

int main()
{
	Solution so;

	vector<int> nums1 = { 1,2,2,1 };
	vector<int> nums2 = { 2,2 };

	vector<int> num_end = so.intersect(nums1, nums2);
	for (auto item : num_end) {
		cout << item << " ";
	}
	cout << endl;

	return 0;
}