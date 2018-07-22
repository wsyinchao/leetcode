#include<iostream>

#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

char ch_arr[] = "0123456789";

class Solution {
public:
	//date
	vector<string> m_v;

	string countAndSay(int n) {
		initialM_v(n);

		return m_v[n];
	}

	void initialM_v(int counts) {
		if (counts == 2) {
			m_v.push_back("11");
		}
		else if (counts > 2) {
			initialM_v(counts - 1);

			string ss = m_v[counts - 1];

			//deal with ss;
			int i = 0;
			int len = ss.size();
			char ch = ss[0];
			int counts_t = 0; //I am assume the value of 'counts' is less than 10.
			string ss_temp = "";
			while (i <= len - 1) {
				if (ss[i] == ch) {
					++counts_t;
					++i;
				}
				else {
					char ch_temp = ch_arr[counts_t];
					ss_temp = ss_temp + ch_temp;
					ss_temp = ss_temp + ch;

					counts_t = 0;

					ch = ss[i];
				}
			}

			if (counts_t != 0) {
				char ch_temp = ch_arr[counts_t];
				ss_temp = ss_temp + ch_temp;
				ss_temp = ss_temp + ch;
			}

			m_v.push_back(ss_temp);
		}
		else {
			return;//do nothing.
		}
	}

	Solution() {
		m_v.push_back("1");
		m_v.push_back("1");//initial...
		//initialM_v(50);
	}
};

int main()
{
	Solution so;
	//so.countAndSay(1);
	so.initialM_v(10);
	//to_string() //convert int to string.
	//atoi() ///convert string to int.
	//strtol() ///convert string to long integer.
	//itoa() ///convert int to string.

	return 0;
}