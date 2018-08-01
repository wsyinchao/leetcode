#include<iostream>

using namespace std;


// Definition for a Node.
class Node {

public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	int maxDepth(Node* root) {
		//reference "max number depth of binary tree"'s solution.
		if (root == NULL) {
			return 0;
		}

		int len = root->children.size();
		int maxnun = 0;
		for (int i = 0; i < len; ++i) {
			maxnun = max(maxnun, maxDepth(root->children[i]));
		}

		return maxnun + 1;
	}
};

int main()
{


	return 0;
}