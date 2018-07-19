#include<iostream>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		long ret = 0;
		int posPower = 10;
		while (x != 0) {
			ret = ret * posPower + (x % 10);

			if (ret > INT_MAX || ret < INT_MIN) {
				return 0;
			}

			x /= 10;
		}

		return static_cast<int> (ret);
	}
};

int main()
{
	Solution so;
	cout <<so.reverse(-34236469)<<endl;

	cout << -12 % 10 << endl;

	return 0;
}