#include<iostream>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *pL1 = l1;
		ListNode *pL2 = l2;

		ListNode * head = NULL;
		ListNode * ret = NULL;

		while (pL1 != NULL && pL2 != NULL) {
			ListNode * tempNode = NULL;//just a point type
			if (pL1->val <= pL2->val) {
				tempNode = pL1;
				pL1 = pL1->next;
			}
			else {
				tempNode = pL2;
				pL2 = pL2->next;
			}

			subMerge(head, ret, tempNode);
		}

		if (pL1 != NULL) {
			subMerge(head, ret, pL1);
		}

		if (pL2 != NULL) {
			subMerge(head, ret, pL2);
		}

		return ret;
	}

	void subMerge(ListNode * &head, ListNode * &ret, ListNode * tempNode)
	{
		if (head == NULL) {
			head = tempNode;
			ret = head;
		}
		else {
			head->next = tempNode;
			head = tempNode;
		}
	}
};

int main()
{
	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(2);
	ListNode * l3 = new ListNode(4);
	ListNode * l4 = new ListNode(1);
	ListNode * l5 = new ListNode(3);
	ListNode * l6 = new ListNode(4);

	l1->next = l2;
	l2->next = l3;
	l4->next = l5;
	l5->next = l6;

	Solution so;
	so.mergeTwoLists(l1, l4);

	return 0;
}