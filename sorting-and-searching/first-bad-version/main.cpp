#include<iostream>

#include<algorithm>
#include<climits>
#include<ctime>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
	if (version > INT_MAX >> 1) {
		return true;
	}

	return false;
}

class Solution {
public:
	int firstBadVersion(int n) {
		//dichotomy search.
		int l = 1;
		int h = n;

		while (l < h) {
			int index = l + ((h - l) >> 1);
			if (isBadVersion(index)) {
				h = max(index - 1, l);
			}
			else {
				l = min(index + 1, h);
			}
		}

		if (l == h) {
			if (isBadVersion(l)) {
				return l;
			}
			else {
				return l + 1; //This reason of "return l + 1" is 问题本身的性质决定.
			}
		}
	}
};

int main()
{
	Solution so;
	for (int i = 0; i < 10000; ++i) {
		//cout << so.firstBadVersion(INT_MAX) << endl; //linux 环境，速度快很多?....在
		//so.firstBadVersion(INT_MAX);
	}
	cout << clock(); //15s

	return 0;
}