#include<iostream>

#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double ret = INT_MIN;

		int len = nums.size();
		for (int i = k - 1; i < len; ++i) {
			int tk = k;
			double sum = 0;
			while (tk) { //If can remove this loop?
				sum += nums[i - tk + 1];
				--tk;
			}
			double average = sum / k;
			if (average > ret) {
				ret = average;
			}
		}

		return ret;
	}
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(12);
	v.push_back(-5);
	v.push_back(-6);
	v.push_back(50);
	v.push_back(3);

	Solution so;
	/*for (int i = 0; i < 100; ++i) {
		cout << so.findMaxAverage(v, 4) << endl;
	}*/

	return 0;
}