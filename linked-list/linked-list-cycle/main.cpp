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

/*
	The idea is to have two references to the list and move them difference speeds, move one by 1 node and the other by 2 node.
	* If list have a loop they will definitely meet.
	* Else either of them(or their next) will be NULL.

	And How to prove it?
	From stack overflow-->
	Note that when both tortoise and hare in the cycle, their relative speed becomes 1, virtually hare chases standing tortoise with 
	this speed.so hare will meet tortoise in N <= cycle's len steps.
	You can replace "two steps" with "three steps", buy you have to check whether they meet at every hare substep

	This question is first part of Floyd algorithm is cycle detection.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode * node_1 = head;
		ListNode * node_2 = head;

		while (node_1 != NULL && node_1->next != NULL && 
			node_2 != NULL && node_2->next != NULL && node_2->next->next != NULL) {

			node_1 = node_1->next;
			node_2 = node_2->next->next;

			if (node_1 == node_2) {
				return true;
			}
		}

		return false;
	}
};

int main()
{
	Solution so;

	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(2);
	ListNode * l3 = new ListNode(3);

	l1->next = l2;
	l2->next = l3;
	//l3->next = l1;

	cout << so.hasCycle(l1) << endl;

	return 0;
}