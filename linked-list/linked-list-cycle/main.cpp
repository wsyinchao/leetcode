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
	* Else either of them(ot their next) will be NULL.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {

	}
};

int main()
{
	return 0;
}