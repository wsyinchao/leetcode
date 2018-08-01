#include<iostream>

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		//The be given data of binary tree is middle-order.
		//If given the binary tree is [3,9,20,null,null,15,7], and the max depth is 3.
		//This problems can be solved either breadth-first or depth-first traversal.

		//In this problem, I will get the depth by depth-first traversal.
		if (root == NULL) {
			return 0;
		}

		return max( maxDepth(root->left), maxDepth(root->right) ) + 1;
	}
};

int main()
{
	return 0;
}
