#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//To understand again. I think I am not really understand it.
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int l1 = nums1.size();
		int l2 = nums2.size();

		if (l1 > l2) {//to ensure l1 left than l2
			return findMedianSortedArrays(nums2, nums1);
		}

		int iMin = 0, iMax = l1;
		int halfManLen = (l1 + l2 + 1) / 2;
		while (iMin < iMax){
			int i = (iMin + iMax) / 2;
			int j = halfManLen - i;

			if (nums1[i - 1] <= nums2[j] && nums2[j - 1] <= nums1[i]){
				//find the i object.
				if ((l1 + l2) % 2 == 0){//if m+n is odd.
					return max(nums1[i - 1], nums2[j - 1]);
				}
				else if ((l1 + l2) % 2 == 1){//if m+n is even.
					double median = max(nums1[i - 1], nums2[j - 1]) + min(nums1[i], nums2[j]);
					median /= 2;
					return median;

				}
			}
			else if (nums1[i - 1] > nums2[j]){
				iMax -= 1;
			}
			else if (nums2[j - 1] > nums1[i]){
				iMin += 1;
			}
		}

		return 0.0;
	}
};

int main()
{

	return 0;
}