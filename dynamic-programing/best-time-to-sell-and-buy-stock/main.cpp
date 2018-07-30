#include<iostream>

#include<vector>

//#include<algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		int min_ = prices[0];

		if (!prices.empty()) {
			int len = prices.size();
			int i = 0;
			while (i < len) {
				int diff = prices[i] - min_;
				if (diff < 0) {
					min_ = prices[i];
				}
				else if (profit < diff) {
					profit = diff;
				}
			}
		}

		return profit
	}
};

int main()
{

	return 0;
}
