#include<iostream>

#include<vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int n = 0; 
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
			n = n ^ *it;
		}

		return n;
	}
};

int main()
{


	return 0;
}