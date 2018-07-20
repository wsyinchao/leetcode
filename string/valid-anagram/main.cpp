#include<iostream>

#include<string>
#include<unordered_map>

using namespace std;

// my way
class Solution {
public:
	bool isAnagram(string s, string t) {
		//my way
		if (s.size() != t.size()) {
			return false;
		}

		unordered_map<char, int> map_s;
		unordered_map<char, int> map_t;

		subIsAnagram(s, map_s);
		subIsAnagram(t, map_t);

		unordered_map<char, int>::iterator it_s = map_s.begin();
		//unordered_map<char, int>::iterator it_t = map_t.begin();
		for (; it_s != map_s.end(); ++it_s) {
			if (map_t.find(it_s->first) != map_t.end()) {
				if (it_s->second != map_t[it_s->first]) {
					return false;
				}
			}
			else {
				return false;
			}
		}

		return true;
	}

	void subIsAnagram(string& s, unordered_map<char, int>& map) {
		for (int i = 0; i < s.size(); ++i) {
			unordered_map<char, int>::iterator it = map.find(s[i]);
			if (it != map.end()) { //find it
				it->second++;
			}
			else {
				map[s[i]] = 1;
			}
		}
	}
};

//The other best way
//思路是一样的，方法是一样的
//我用的是 unordered_map 利用字母本身作为索引，别人用的是 字母 - 'a' 的值作为索引(可以避开使用map容器,)
//该方法的确定是 一定要求字母只有26个，不支持 unicode 字符。相比之下，我的方法更好.
//class Solution {
//public:
//	bool isAnagram(string s, string t) {
//		int scount[26] = { 0 };
//		int tcount[26] = { 0 };
//
//		if (s.size() != t.size()) return false;
//
//		int len = s.size();
//
//		int i = 0;
//		for (i = 0; i < len; ++i) {
//			scount[s[i] - 'a']++;
//			tcount[t[i] - 'a']++;
//
//		}
//
//		for (i = 0; i < len; ++i) {
//			if (scount[s[i] - 'a'] != tcount[s[i] - 'a']) return false;
//
//		}
//		return true;
//	}
//};

int main()
{
	Solution so;
	cout << so.isAnagram("anagram", "nagaram") << endl;

	return 0;
}
