#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool isPalindrome(const string& s){
		for (size_t i = 0; i < s.size() / 2; ++i){
			if (s[i] != s[s.size() - 1 - i]){
				return false;
			}
		}

		return true;
	}

	//寻找最长会问子字符串
	//brute-force
	string longestPalindrome(const string& s) {
		string ss;
		string palindrome;

		for (size_t j = 0; j < s.size(); ++j){
			ss.clear();
			for (size_t i = j; i < s.size(); ++i){
				ss = ss + s[i];
				if (this->isPalindrome(ss) && palindrome.size() < ss.size()){
					palindrome = ss;
				}
			}
		}

		return palindrome;
	}
};

int main()
{
	Solution so;
	string s("aaaaaaaaaa");
	cout << s.size() << endl;

	cout << so.longestPalindrome(s) << endl;

	return 0;
}