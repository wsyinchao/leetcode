#include<iostream>

#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	//This way is easy and understandable
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int len = m + n;

		//first, merge to nums1;
		int i = 0;
		while (i < n) {
			nums1[m++] = nums2[i++];
		}

		vector<int>::iterator reallyEnd = nums1.begin() + len;

		//finally, sorted.
		sort(nums1.begin(), reallyEnd);
	}
};

int main()
{

	return 0;
}