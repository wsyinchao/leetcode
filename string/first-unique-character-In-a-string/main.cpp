#include<iostream>

#include<string>
#include<unordered_map>
#include<list>
#include<algorithm>

using namespace std;

typedef struct obj
{
	int pos;
	int counts;
	list<int>::const_iterator it; //The iterator of a list
	bool isErase; //is erase
}struc;

class Solution {
public:
	/*
		For this type of problem, you should to avoid twice loop.
		Complete all works in once loop.
	*/
	int firstUniqChar(string s) {
		//unordered_map<char, struc> mymap;
		//list<int> l;

		//for (int i = 0; i < s.size(); ++i) {
		//	unordered_map<char, struc>::iterator it = mymap.find(s[i]); //The performance will be consumed for every query
		//	if (it != mymap.end()) { //find it;
		//		//it->second.counts++;

		//		if (!it->second.isErase) {
		//			l.erase(it->second.it);
		//			it->second.isErase = true;
		//		}
		//	}
		//	else {
		//		l.push_back(i);

		//		struc struc_;
		//		struc_.pos = i;
		//		struc_.counts = 1;
		//		struc_.it = --l.end();
		//		struc_.isErase = false;

		//		mymap[s[i]] = struc_;
		//	}
		//}

		//int ret = -1;
			////for (map<char, struc>::iterator it = mymap.begin(); it != mymap.end(); ++it) { //look for the smallest value by loop.
			////	if (it->second.counts == 1) {
			////		if (ret == -1) {
			////			ret = it->second.pos;
			////		}
			////		else if (ret > it->second.pos) {
			////			ret = it->second.pos;
			////		}
			////	}
			////}
		//if (!l.empty()) {
		//	ret = l.front();
		//}

		//return ret;

		//The other best way to resolve it
		list<int> l;
		vector<list<int>::iterator> v(26, l.begin());
		vector<int> repeat(26, 0);

		char ch;
		int ind;
		for (int i = 0; i < s.size(); ++i) {
			ch = s[i];
			ind = ch - 'a';

			repeat[ind]++;

			if (repeat[ind] == 1) {
				l.push_back(i);
				v[ind] = --l.end();
			}
			else if (repeat[ind] == 2) {
				l.erase(v[ind]);
			}
			else {
				continue;
			}
		}

		return l.empty() ? -1 : l.front();

		//The more best way.
		//good algorithm.
		//vector<int> v(26, -2);
		//char ch;
		//int ind;
		//for (int i = 0; i < s.size(); ++i) {
		//	ch = s[i];
		//	ind = ch - 'a';

		//	v[ind] = v[ind] == -2 ? i : -1;//If it has been repeated, set to -1
		//}

		//int ret = -1;
		//for (auto x : v) {
		//	ret = x >= 0 ? (ret >= 0 ? min(ret, x) : x) : ret;
		//}

		//return ret;
	}
};

int main()
{
	string s("leetcode");
	Solution so;
	cout << so.firstUniqChar(s) << endl;

	
	//vector<int> pos(26, -2);
	//for (int i = 0; i != s.size(); ++i)
	//	pos[s[i]-'a'] = pos[s[i]-'a'] == -2 ? i : -1;//if it has been repeated, set the value to -1

	//int res = -1;
	//for (int x : pos)
	//	res = x >= 0 ? (res >= 0 ? min(res, x): x) : res;
	//return res;
	

	return 0;
}