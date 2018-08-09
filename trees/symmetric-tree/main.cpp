#include<iostream>

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
	bool isSymmetric(TreeNode* root) {
		return subIsSymmetric(root, root);
	}

	bool subIsSymmetric(TreeNode * leftSubTree, TreeNode * rightSubTree) {
		if (leftSubTree == NULL && rightSubTree == NULL) {
			return true;
		}
		if (leftSubTree == NULL || rightSubTree == NULL) {
			return false;
		}

		return leftSubTree->val == rightSubTree->val &&
			subIsSymmetric(leftSubTree->left, rightSubTree->right) &&
			subIsSymmetric(leftSubTree->right, rightSubTree->left);
	}
};

int main()
{

	return 0;
}
