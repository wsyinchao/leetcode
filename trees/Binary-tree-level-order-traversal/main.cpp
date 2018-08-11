#include<iostream>

#include<vector>

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
	vector<vector<int>> m_v;

	vector<vector<int>> levelOrder(TreeNode* root) {
		//level order traversal
		vector<int> ret;

		if (root == NULL) return m_v;

		ret.push_back(root->val);

		m_v.push_back(ret);

		if (root->left != NULL) {
			levelOrder(root->left);
		}
		if (root->right != NULL) {
			levelOrder(root->right);
		}

		return m_v;
	}
};

int main()
{
	return 0;
}