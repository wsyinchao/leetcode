#include<iostream>

#include<string>
#include<cctype>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int i = 0;
		int j = str.size();
		while (i < j && str[i] == ' ') {//First discard as many whitespace characters as necessary until the first 
							   //non-whitespace character is found.
			++i;
		}

		//
		int syn = 1;
		if (str[i] == '-') {
			syn = -1;
			++i;
		}
		else if (str[i] == '+') {
			++i;
		}

		if (i >= j || (!isdigit(str[i]))) {
			return 0;
		}

		//
		long long ret = 0;
		while (i < j) {
			if (!isdigit(str[i])) {
				break;
			}

			ret = ret * 10 + str[i] - '0';
			++i;

			if (ret * syn <= INT_MIN) {
				return INT_MIN;
			}
			else if (ret * syn >= INT_MAX) {
				return INT_MAX;
			}
		}

		ret = ret * syn;
		return static_cast<int>(ret);
	}
};

int main()
{
	Solution so;
	/*cout << so.myAtoi("42") << endl;
	cout << so.myAtoi("   -42") << endl;
	cout << so.myAtoi("4193 words") << endl;
	cout << so.myAtoi("words and 987") << endl;
	cout << so.myAtoi("-91283472332") << endl;
	cout << so.myAtoi("3.1415926") << endl;
	cout << so.myAtoi("+3") << endl;*/
	cout << so.myAtoi("9223372036854775808") << endl;
	return 0;
}