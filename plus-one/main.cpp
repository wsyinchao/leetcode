#include<iostream>

#include<vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		for (vector<int>::reverse_iterator rit = digits.rbegin();
			rit != digits.rend(); ++rit) {

			*rit = *rit + carry;
			carry = *rit / 10;
			*rit = *rit % 10;

			if (carry == 0) {
				break;
			}
		}

		if (carry != 0) {
			digits.insert(digits.begin(), carry);
		}

		return digits;
	}
};

int main()
{
	vector<int> digits1 = { 1,2,3 };
	vector<int> digits2 = { 9,9,9,9 };

	Solution so;
	so.plusOne(digits1);
	so.plusOne(digits2);

	for (auto item : digits1) {
		cout << item << " ";
	}
	cout << endl;

	for (auto item : digits2) {
		cout << item << " ";
	}
	cout << endl;

	return 0;
}