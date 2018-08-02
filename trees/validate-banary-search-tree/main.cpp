#include<iostream>

#include<climits>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		//should resolve it with recursively.
		
		//check leaf nodes counts.
		return subIsValidBST(root, LONG_MIN, LONG_MAX);
	}

	bool subIsValidBST(TreeNode* node, long l, long r) {
		if (node == NULL) {
			return true;
		}

		if (l >= node->val || r <= node->val) {
			return false;
		}

		return subIsValidBST(node->left, l, node->val) && subIsValidBST(node->right, node->val, r);

	}
};

int main()
{
	

	return 0;
}
