#include<iostream>

#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		//
		int len = strs.size();
		int j = 0;
		bool flag = true;
		string chs;
		char ch = ' ';

		while (true) {
			flag = true;
			for (int i = 0; i < len; ++i) {
				if (j == strs[i].size()) {
					flag = false;
					break;
				}

				if (i == 0) {
					ch = strs[i][j];
				}
				else {
					if (ch == strs[i][j]) {
					}
					else {
						flag = false;
						break;
					}
				}
			}

			if (flag && ch != ' ') {
				chs = chs + ch;
				++j;
			}
			else {
				break;
			}
		}

		return chs;
	}
};

int main()
{
	vector<string> vs;
	//vs.push_back("dog");
	/*vs.push_back("racecar");
	vs.push_back("car");*/

	Solution so;
	cout << so.longestCommonPrefix(vs) << endl;

	/*
		最近两个，是靠调试写出来的，这不行，我更需要锻炼思维的严谨性...
	*/

	return 0;
}
