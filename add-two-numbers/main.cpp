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
	//my solution
	////abstract the process of calculate
	//int precessOfCalculate(int v1, int v2, int &carry) {
	//	int tv = v1 + v2 + carry;
	//	carry = tv / 10;
	//	tv %= 10;

	//	return tv;
	//}
	////add new node to linked List
	//void addNode2LinkedList(ListNode **&bottomPoint, int val) {
	//	ListNode *tnode = new ListNode(val);
	//	*bottomPoint = tnode;
	//	bottomPoint = &tnode->next; //更新尾指针
	//}

	//ListNode * addTwoNumbers_self(ListNode* l1, ListNode* l2) {
	//	ListNode *res = new ListNode(-1);
	//	ListNode **bottomPoint = &res->next; //保存尾指针

	//	int carry = 0;
	//	while (l1 != nullptr && l2 != nullptr)
	//	{
	//		int tv = this->precessOfCalculate(l1->val, l2->val, carry);

	//		if (res->val == -1)
	//		{
	//			res->val = tv;
	//		}
	//		else
	//		{
	//			this->addNode2LinkedList(bottomPoint, tv);
	//		}
	//		l1 = l1->next;
	//		l2 = l2->next;
	//	}

	//	//if l1's length more than l2
	//	while (l1 != nullptr)
	//	{
	//		int v = this->precessOfCalculate(l1->val, 0, carry);

	//		this->addNode2LinkedList(bottomPoint, v);
	//		l1 = l1->next;
	//	}
	//	//else
	//	while (l2 != nullptr)
	//	{
	//		int v = this->precessOfCalculate(0, l2->val, carry);

	//		this->addNode2LinkedList(bottomPoint, v);
	//		l2 = l2->next;
	//	}

	//	//
	//	if(carry != 0)
	//	{
	//		this->addNode2LinkedList(bottomPoint, carry);
	//		carry = 0;
	//	}

	//	return res;
	//}
	
	//learned solution
	ListNode * addTwoNumbers_1(ListNode* l1, ListNode* l2) {
		//ListNode *res = new ListNode(0);//申请一个节点比较消耗内存，不建议
		//ListNode *res_answer = res;

		ListNode *res = nullptr;//申请一个节点比较消耗内存，不建议
		ListNode *res_answer = nullptr;

		int carry = 0;
		while (l1 != nullptr || l2 != nullptr || carry != 0 )
		{
			//循环之中不要有判断，影响效率 //有的少不了，尽量减少...

			int v1 = l1 == nullptr ? 0 : l1->val;
			int v2 = l2 == nullptr ? 0 : l2->val;

			int v = v1 + v2 + carry;
			carry = v / 10;
			v %= 10;

			if (res == nullptr) {
				res = new ListNode(v);
				res_answer = res;
			}
			else {
				res->next = new ListNode(v);
				res = res->next;
			}

			l1 = l1 == nullptr ? nullptr : l1->next;
			l2 = l2 == nullptr ? nullptr : l2->next;
		}

		return res_answer;
	}

	//learned solution2
	//此方法更好，很巧妙，但是如果循环重复调用，会造成申请很多的节点，导致在leetcode上性能更差
	//我更喜欢这个方法...
	//ListNode * addTwoNumbers_2(ListNode* l1, ListNode* l2) {
	//	ListNode *res = new ListNode(0);//申请一个节点比较消耗内存，不建议
	//	ListNode *res_answer = res;

	//	int carry = 0;
	//	while (l1 != nullptr || l2 != nullptr || carry != 0)
	//	{
	//		//循环之中不要有判断，影响效率 //有的少不了，尽量减少...

	//		int v1 = l1 == nullptr ? 0 : l1->val;
	//		int v2 = l2 == nullptr ? 0 : l2->val;

	//		int v = v1 + v2 + carry;
	//		carry = v / 10;
	//		v %= 10;

	//		res->next = new ListNode(v);
	//		res = res->next;

	//		l1 = l1 == nullptr ? nullptr : l1->next;
	//		l2 = l2 == nullptr ? nullptr : l2->next;
	//	}

	//	return res_answer->next;
	//}
};

int main()
{

	return 0;
}