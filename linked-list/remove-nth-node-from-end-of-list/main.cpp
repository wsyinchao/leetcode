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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode* thead = head; //save the head

		//get the len of a linked list.
		int len = 1;
		ListNode* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
			++len;
		}

		if (len == 1) {//if len == 1 means remove all nodes.
			delete thead;
			return NULL;
		}

		if (len == n) {//It's means delete the head node.
			ListNode* ttt = thead;
			thead = thead->next;
			delete ttt;
			return thead;
		}

		//find the previous node of the node you want to delete.
		int tn = len - n;
		temp = head;
		while (--tn) {
			temp = temp->next;
		}

		if (temp->next->next != NULL) {
			ListNode* tt = temp->next->next;
			*(temp->next) = *(temp->next->next); //need to free memory?
			delete tt;
		}
		else {
			temp->next = NULL;
		}

		return thead;
	}
};


int main()
{
	ListNode* list = new ListNode(1);
	ListNode* list2 = new ListNode(2);
	list->next = list2;

	Solution so;
	so.removeNthFromEnd(list, 2);

	return 0;
}