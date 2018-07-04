#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

//The best time to buy and sell stock.
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0; //the profit of stock
		for (size_t index = 0 + 1; index < prices.size(); ++index)
		{
			profit += max(prices[index] - prices[index - 1], 0);
		}

		return profit;
	}
};

int main()
{
	Solution so;
	vector<int> v{ 7, 1, 5, 3, 6, 4 };
	cout << so.maxProfit(v) << endl;

	return 0;
}