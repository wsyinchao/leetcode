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
		//The other way to solve this.
		vector<short> col(9, 0); //ÿһ�� �оŸ����ݣ�ÿһ��������һ�� short�ֽ�
		vector<short> block(9, 0); //ÿһ��С����
		vector<short> row(9, 0); //ÿһ��

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int idx = 1 << (board[i][j] - '0'); //����ط��е㼼������������ͬ������ת���ɶ�Ӧ�ڲ�ͬλ�ϵ� 1.

					//How the block[i / 3 * 3 + j / 3] works?
					//����ͬλ�ã�������һ��С�����еı�����һ�� 
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