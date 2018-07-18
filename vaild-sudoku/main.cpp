/*
	����ת�ַ���
	char str[2];
	sprintf(str, "%d", 10); //ʹ��sprintf()

	�ַ���ת����
	chat str[] = "12345";
	int a;
	sscanf(str, "%d", &a); //ʹ��sscanf()
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
		//��д�˱��˵ķ���
		vector<short> row(9, 0);
		vector<short> col(9, 0);
		vector<short> block(9, 0);

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					short index = 1 << (board[i][j] - '0');
					if (row[i] & index || col[j] & index || block[i / 3 * 3 + j / 3]) {
						return false;
					}

					row[i] |= index;
					col[j] |= index;
					block[i / 3 * 3 + j / 3] |= index;
				}
			}
		}

		return true;
	}
};

int main()
{

	return 0;
}