#include<iostream>

#include<string>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		for (int i = 0; i < s.size() / 2; ++i) {
			swap(s[i], s[s.size() - 1 - i]);
		}

		return s;
	}
};

int main()
{
	return 0;
}