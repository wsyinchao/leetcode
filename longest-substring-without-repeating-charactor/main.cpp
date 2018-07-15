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
				//��ʾû�г����ظ���
				subString[s[i]] = i;
			}
			else {
				//�������ظ���

				//�ҵ�ƥ�䵽�˵�map,���Ҵ�ƥ�����һ�����������ȡ map
				unordered_map<char, int> map2;
				int index = subString.find(s[subString.find(s[i])->second + 1])->second;//������˳��
				for (int k = index; k < i; ++k) {
					map2[s[k]] = k;
				}

				subString = map2;
				subString[s[i]] = i;
			}

			if (len < subString.size()) {//���Ѿ����ڵ����ַ����ĳ���
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