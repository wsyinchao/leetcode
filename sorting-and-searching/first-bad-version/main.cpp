#include<iostream>

#include<algorithm>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
	if (version == 1702766719) {
		return true;
	}

	return false;
}

class Solution {
public:
	int firstBadVersion(int n) {
		//dichotomy search.
		long long l = 1;
		long long h = n;

		while (l < h) {
			long long index = (l + h) / 2;
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
	cout << so.firstBadVersion(2126753390) << endl;

	return 0;
}