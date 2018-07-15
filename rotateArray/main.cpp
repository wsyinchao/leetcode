#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		//loop move the arr element.
		//int reallyK = k % nums.size();
		//while (reallyK--) { //this way is time limit exceeded...
		//	vector<int>::reverse_iterator it = nums.rbegin();
		//	int temp = *it;
		//	for (; it != nums.rend(); ++it)
		//	{
		//		if ((it + 1) != nums.rend()) {
		//			*it = *(it + 1);
		//		}
		//		else {
		//			*it = temp;
		//		}
		//	}
		//}

		//The more effective way.
		if (k == 0) return;
		int r = k % nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + r);
		reverse(nums.begin() + r, nums.end());

		/*
			use .begin and .end
			reverse ��������һ��������ʾҪ�����ĵ�һ��Ԫ�أ��ڶ���������ʾҪ�����ĵڶ�����������һ��λ��...
		*/
		//reverse(nums.begin(), nums.begin() + 7);
	}
};

void printArr(vector<int> arr)
{
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	//vector<int> arr = { 1,2,3,4,5,6,7 }; --c++98��֧�����ֳ�ʼ�� c11��֧�ֵĳ�ʼ��������
	int arr2[] = { 1,2,3,4,5,6,7 };
	vector<int> arr(arr2, arr2 + 7);
	int k = 3;

	printArr(arr);

	Solution so;
	so.rotate(arr, k);

	printArr(arr);

	return 0;
}
