#include<iostream>

#include<string>
#include<cctype> //判断一个字符是否是字母或者数字的方法 isalnum 的头文件

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		//Define two pointers that point to the beginning and the end respectively
		int i = 0;
		int j = s.size() - 1;

		while (i < j) {
			//check i 
			if (!isalnum(s[i])) {
				++i;
				continue;
			}

			//check j
			if (!isalnum(s[j])) {
				--j;
				continue;
			}

			if (tolower(s[i]) != tolower(s[j])) {
				return false;
			}

			++i;
			--j;
		}

		return true;
	}
};

int main()
{
	Solution so;
	cout << so.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << so.isPalindrome("race a car") << endl;

	return 0;
}