#include <iostream>
#include <algorithm>
#include <string>
#include <cstdint>
using namespace std;

class Solution {
public:
	//bool is over flow
	/*bool isOverFlow(int x, int y){
		int z = x + y;

		if (x > 0 && y > 0 && z < 0){
		return true;
		}

		if (x < 0 && y < 0 && z > 0){
		return true;
		}

		return false;
		}*/

	//solution
	//int reverse(int x) {
	//	int res = 0;
	//	while (x != 0){
	//		/*if (isOverFlow(res * 10, x % 10)){
	//			return 0;
	//		}*/
	//		if (res != res * 10 / 10){ //overflow
	//			return 0;
	//		}

	//		res = res * 10 + x % 10;//每一次在原来的基础上扩大10倍 再加上尾数
	//		x /= 10;
	//	}

	//	return res;
	//}

	int reverse(int x){
		long long res = 0;
		while (x != 0){
			res = res * 10 + x % 10;
			x /= 10;
		}

		if (res > INT32_MAX || res < INT32_MIN){
			res = 0;
		}

		return static_cast<int>(res);
	}
};

int main()
{
	//for (int i = 2000000000; i > 0; ++i)
	//{
	//	if (i + 1 < 0){
	//		cout << i;//-2147483648, 2147483647
	//		break;
	//	}
	//}

	Solution so;
	////cout << so.reverse(2000000000) << endl;
	int x = 0;
	while (cin >> x){
		cout << so.reverse(x) << endl;
	}

	//cout << INT32_MAX << endl;

	return 0;
}
