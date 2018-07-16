#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> subString;
		int len = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (subString.find(s[i]) == subString.end()) {
				//表示没有出现重复的
				subString[s[i]] = i;
			}
			else {
				//出现了重复的

				//找到匹配到了的map,并且从匹配的那一个单词往后截取 map
				unordered_map<char, int> map2;
				int index = subString.find(s[subString.find(s[i])->second + 1])->second;//依赖于顺序
				for (int k = index; k < i; ++k) {
					map2[s[k]] = k;
				}

				subString = map2;
				subString[s[i]] = i;
			}

			if (len < subString.size()) {//求已经存在的子字符串的长度
				len = subString.size();
			}
		}

		return len;
	}
};

int main()
{
	string s("anviaj");
	Solution so;

	int len = so.lengthOfLongestSubstring(s);

	cout << len << endl;

	return 0;
}