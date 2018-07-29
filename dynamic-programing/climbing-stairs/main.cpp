#include<iostream>

#include<vector>

using namespace std;

class Solution {
public:
	vector<int> arr;

	//How to understand it? arr[n] = arr[n - 1] + arr[n - 2]?
	//Because only move 1 step or 2 step every times, so if in n step, it must come from n - 2 step or n - 1 step.
	int climbStairs(int n) {
		if (n == 1) {
			if (arr.empty()) {
				arr.push_back(1);
			}
			return 1;
		}
		else if (n == 2) {
			if (arr.empty()) {
				arr.push_back(1);
			}

			if (arr.size() >= n) {
				return arr[n - 1];
			}
			arr.push_back(2);
			return 2;
		}
		else {
			if (arr.size() >= n) {
				return arr[n - 1];
			}
			else {
				arr.push_back(climbStairs(n - 2) + climbStairs(n - 1));
				return arr.back();
			}
		}
	}
};

int main()
{
	Solution so;
	//cout << so.climbStairs(44) << endl;
	int n;
	while (cin >> n) {
		cout << "out-->" << so.climbStairs(n) << endl;
	}

	return 0;
}