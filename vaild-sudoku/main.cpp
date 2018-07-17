/*
	数字转字符串
	char str[2];
	sprintf(str, "%d", 10); //使用sprintf()

	字符串转数字
	chat str[] = "12345";
	int a;
	sscanf(str, "%d", &a); //使用sscanf()
*/

#include<iostream>
#include<cstdio>

#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		//The other way to solve this.
		vector<short> col(9, 0); //每一列 有九个数据，每一个数据是一个 short字节
		vector<short> block(9, 0); //每一个小方块
		vector<short> row(9, 0); //每一行

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int idx = 1 << (board[i][j] - '0'); //这个地方有点技术。。。将不同的数字转换成对应在不同位上的 1.

					//How the block[i / 3 * 3 + j / 3] works?
					//将不同位置，但是在一个小方块中的保存在一起 
					if (row[i] & idx || col[j] & idx || block[i / 3 * 3 + j / 3] & idx)
						return false;
					row[i] |= idx;
					col[j] |= idx;
					block[i / 3 * 3 + j / 3] |= idx;
				}
			}
		return true;
	}
};

int main()
{

	return 0;
}