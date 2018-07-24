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
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * reverseList(ListNode* head) {
		if (head == NULL) {
			return NULL;
		}

		static ListNode * retNode = NULL;
		static ListNode * reallyNode = head;
		if (reallyNode == NULL) {
			reallyNode = head;
		}

		//implement for recursively
		if (head->next != NULL) {
			reverseList(head->next)->next = head; //It works.
			if (head == reallyNode) {
				head->next = NULL;
				reallyNode = NULL;

				return retNode;
			}
			return head;
		}
		else {
			retNode = head;
			if (head == reallyNode) {
				reallyNode = NULL;
			}
			return head;//head node
		}
	}
};

int main()
{
	ListNode *l = new ListNode(1);
	ListNode *ll = new ListNode(2);
	ListNode *lll = new ListNode(3);
	ListNode *llll = new ListNode(4);
	ListNode *lllll = new ListNode(5);

	l->next = ll;
	ll->next = lll;
	lll->next = llll;
	llll->next = lllll;

	ListNode *s = new ListNode(1);
	ListNode *ss = new ListNode(2);
	ListNode *sss = new ListNode(3);
	ListNode *ssss = new ListNode(4);
	ListNode *sssss = new ListNode(5);

	s->next = ss;
	/*ss->next = sss;
	sss->next = ssss;
	ssss->next = sssss;*/

	Solution so;
	ListNode* lret = so.reverseList(l);
	ListNode* lret2 = so.reverseList(s);

	/*
		最终还是完成了，不容易。。。
		遇到的问题(1) --> 所使用的编译器和 leetcode 的在线编译器不一样，有一些不规范(或者说错误)的写法，本地没报错， leetcode 编译无法通过.
				(2) --> 代码的严谨性不好，因为使用了静态变量，导致测试用例之间会彼此影响，而消除这些影响的代码，没写好....调试了点时间.

		改进		(1) --> 如果需要使用静态变量完成要求，需要格外注意静态变量可能造成的影响.
				(2) --> 对于有限集合中的每一个元素的操作是一样的，且有终止条件(本例中，尾节点->next == null 即为终止条件), 可以考虑递归.
	*/

	return 0;
}