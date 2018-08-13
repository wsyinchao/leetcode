#include<iostream>

#include<vector>
#include<queue>

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
		if (root == NULL) {
			return m_v;
		}

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) { //complete level order traversal. Now, we must to store every level of binary tree to m_v;
			//each loop means operator for one nodes.
			vector<int> tv;
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				TreeNode* tempNode = q.front();
				q.pop();
				tv.push_back(tempNode->val);
				if (tempNode->left != NULL) q.push(tempNode->left);
				if (tempNode->right != NULL) q.push(tempNode->right);
			}
			m_v.push_back(tv);
		}

		return m_v;
	}
};

int main()
{
	return 0;
}