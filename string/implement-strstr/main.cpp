/*
	通过这个实例，应该要会使用库方法，满足工程应用

	strstr()
	const char * strstr ( const char * str1, const char * str2 );
	char * strstr (       char * str1, const char * str2 );

	Locate substring
	Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.

	The matching process does not include the terminating null-characters, but it stops there.

	The base operator of string is in string.h(cstring), you should to learn use it.
*/

#include<iostream>

#include<cstring>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		return 0;
	}

	int index(string haystack, string needle) {
		//这是一个最简单的，易于理解的算法
		int i = 0;
		int i_max = haystack.size();
		int j = 0;
		int j_max = needle.size();

		while (i < i_max && j < j_max) {
			if (haystack[i] == needle[j]) {
				++i;
				++j;
			}
			else { //if not equal, back the point.
				i = i - j + 1;
				j = 0;
			}
		}

		if (j == needle.size()) {
			return i - needle.size();
		}

		return -1;
	}

	//KMP算法，不回溯指针. 克努特-莫里斯-普拉特算法
	//看了半天没太理解，以后有机会，再仔细研究研究吧....
	int index_KMP(string haystack, string needle) {

	}
};

int main()
{
	Solution so;
	//so.strStr("hello", "ll");
	cout << so.index("mississippi", "issi") << endl;
	return 0;
}
