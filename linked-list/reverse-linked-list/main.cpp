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
		���ջ�������ˣ������ס�����
		����������(1) --> ��ʹ�õı������� leetcode �����߱�������һ������һЩ���淶(����˵����)��д��������û���� leetcode �����޷�ͨ��.
				(2) --> ������Ͻ��Բ��ã���Ϊʹ���˾�̬���������²�������֮���˴�Ӱ�죬��������ЩӰ��Ĵ��룬ûд��....�����˵�ʱ��.

		�Ľ�		(1) --> �����Ҫʹ�þ�̬�������Ҫ����Ҫ����ע�⾲̬����������ɵ�Ӱ��.
				(2) --> �������޼����е�ÿһ��Ԫ�صĲ�����һ���ģ�������ֹ����(�����У�β�ڵ�->next == null ��Ϊ��ֹ����), ���Կ��ǵݹ�.
	*/

	return 0;
}