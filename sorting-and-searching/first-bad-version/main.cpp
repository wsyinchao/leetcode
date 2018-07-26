#include<iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int ret = n; //The first bad version

		int low = 0;
		int high = n;

		//dichotomy search.
		int j = n / 2;

		while (j > 0 && j <= n) {
			if (isBadVersion(j)) {
				ret = j;
				//j = (low + high) / 2
			}
			else {
				j = j + (n - j + 1) / 2;
			}
		}

		return ret;
	}
};

int main()
{
	return 0;
}