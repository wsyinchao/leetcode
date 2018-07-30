#include<iostream>

#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
	int maxProfic(vector<int>& prices)
	{
		int profit = 0;

		int len = prices.size();
		for (int i = 1; i < len; ++i) {
			profit += max(0, prices[i] - prices[i - 1]);
		}

		return profit;
	}
};

int main()
{
	return 0;
}