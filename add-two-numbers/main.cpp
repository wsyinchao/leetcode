#include <iostream>
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

//linked list
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	//abstract the process of calculate
	int precessOfCalculate(int v1, int v2, int &carry) {
		int tv = v1 + v2 + carry;
		carry = tv / 10;
		tv %= 10;

		return tv;
	}
	//add new node to linked List
	void addNode2LinkedList(ListNode **&bottomPoint, int val) {
		ListNode *tnode = new ListNode(val);
		*bottomPoint = tnode;
		bottomPoint = &tnode->next; //更新尾指针
	}

	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *res = new ListNode(-1);
		ListNode **bottomPoint = &res->next; //保存尾指针

		int carry = 0;
		while (l1 != nullptr && l2 != nullptr)
		{
			int tv = this->precessOfCalculate(l1->val, l2->val, carry);

			if (res->val == -1)
			{
				res->val = tv;
			}
			else
			{
				this->addNode2LinkedList(bottomPoint, tv);
			}
			l1 = l1->next;
			l2 = l2->next;
		}

		//if l1's length more than l2
		while (l1 != nullptr)
		{
			int v = this->precessOfCalculate(l1->val, 0, carry);

			this->addNode2LinkedList(bottomPoint, v);
			l1 = l1->next;
		}
		//else
		while (l2 != nullptr)
		{
			int v = this->precessOfCalculate(0, l2->val, carry);

			this->addNode2LinkedList(bottomPoint, v);
			l2 = l2->next;
		}

		//
		if(carry != 0)
		{
			this->addNode2LinkedList(bottomPoint, carry);
			carry = 0;
		}

		return res;
	}
};

int main()
{

	return 0;
}