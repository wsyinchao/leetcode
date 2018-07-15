#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//To understand again. I think I am not really understand it.
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len_nums1 = nums1.size();
		int len_nums2 = nums2.size();

		if (len_nums1 > len_nums2){//make sure len_nums1 < len_nums2
			return this->findMedianSortedArrays(nums2, nums1);
		}

		int iMin = 0, iMax = len_nums1;
		int halfLen = (len_nums1 + len_nums2 + 1) / 2;
		while (iMin <= iMax){
			int i = (iMin + iMax) / 2;
			int j = halfLen - i;

			if (i > iMin && nums1[i - 1] > nums2[j]){ //i is too big
				iMax = iMax - 1;
				continue;
			}
			else if (i < iMax && nums2[j - 1] > nums1[i]){ // i is too small
				iMin = iMin + 1;
				continue;
			}
			else { // i is encounter
				int maxLeft = 0;
				if (i == 0){
					maxLeft = nums2[j - 1];
				}
				else if (j == 0){ // that means i == len_nums1
					maxLeft = nums1[i - 1];
				}
				else { //not in edges value
					maxLeft = max(nums1[i - 1], nums2[j - 1]);
				}
				if ((len_nums1 + len_nums2) % 2 == 1) return maxLeft;

				int minRight = 0;
				if (i == len_nums1){
					minRight = nums2[j];
				}
				else if (j == len_nums2){
					minRight = nums1[i];
				}
				else {
					minRight = min(nums1[i], nums2[j]);
				}

				return (minRight + maxLeft) / 2.0;
			}
		}
	}
};

int main()
{
	Solution so;
	vector<int> num1;
	vector<int> num2;

	num1.push_back(1);
	num1.push_back(3);

	num2.push_back(2);

	double res = so.findMedianSortedArrays(num1, num2);

	cout << res << endl;

	return 0;
}