#include<iostream>

#include<vector>

//#include<algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) {
			return 0;
		}

		int profit = INT_MIN;
		int smallestValley = prices[0];

		int len = prices.size();
		//The second number must be larger than the first one.
		for (int i = 0; i < len; ++i) {
			if (prices[i] < smallestValley) {
				smallestValley = prices[i]; // find the smallest valley.
			}

			if (profit < prices[i] - smallestValley) {
				profit = prices[i] - smallestValley;
			}
		}

		return profit;
	}
};

int main()
{

	return 0;
}
