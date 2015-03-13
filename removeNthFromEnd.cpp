#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *first = head;
		ListNode *second = head;
		for (int i = 0; i < n; i++) second = second->next;
		if (second == NULL) {
			head = head->next;
			return head;
		}
		while (second->next != NULL) {
			second = second->next;
			first = first->next;
		}
		first->next = first->next->next;
		return head;
    }
};

void removeNthFromEnd_test_case1() {
	ListNode n1(1),n2(2),n3(3),n4(4),n5(5);
	n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;
	Solution solution;
	ListNode *node = solution.removeNthFromEnd(&n1, 1);
	cout << node->val << endl;

}

void removeNthFromEnd_test_case2() {
	ListNode n1(1);

	Solution solution;
	ListNode *node = solution.removeNthFromEnd(&n1, 1);
	cout << node->val << endl;

}

int main_removeNthFromEnd(int argc, char **argv) {
	removeNthFromEnd_test_case2();
	return 0;
}