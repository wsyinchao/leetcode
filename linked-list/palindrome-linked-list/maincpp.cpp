#include<iostream>

#include<stack>

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
	// O(n)times
	bool isPalindrome(ListNode* head) {
		//可以用括号匹配算法 [error...]
		stack<ListNode*> sta;

		//must to know the len of linked list.
		int len = 0;
		ListNode * thead = head;
		while (thead != NULL) {
			++len;
			thead = thead->next;
		}

		int len2 = 0;
		while (head != NULL) {
			if (len2 == len / 2 && len % 2 != 0 ) {
				head = head->next;
				++len2;
				continue;
			}
			++len2;

			if (!sta.empty()) {
				ListNode * temp = sta.top();
				if (temp->val == head->val) {
					sta.pop();
					head = head->next;
				}
				else {
					sta.push(head);
					head = head->next;
				}
			}
			else {
				sta.push(head);
				head = head->next;
			}
		}

		if (sta.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main()
{
	Solution so;
	so.isPalindrome(NULL);

	return 0;
}