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
    ListNode *deleteDuplicates(ListNode *head) {
		ListNode *r_head = head;
		if (head == NULL) return r_head;
		ListNode *lastNode = head;
		int last_val = head->val;
		while (head != NULL) {
			if (head->val == last_val) head = head->next;
			else {
				lastNode->next = head;
				lastNode = head;
				last_val = head->val;
			}
		}
		lastNode->next = NULL;
		return r_head;
    }
};

void deleteDuplicates_test_case1() {
	ListNode n1(1),n2(1),n3(2),n4(3),n5(3);
	n1.next=&n2; n2.next=&n3; n3.next=&n4; n4.next=&n5;
	
	Solution solution;
	ListNode *r_list = solution.deleteDuplicates(&n1);
	while (r_list != NULL) {
		cout << r_list->val << endl;
		r_list = r_list->next;
	}
}

int main_deleteDuplicates(int argc, char **argv) {
	deleteDuplicates_test_case1();
	return 0;
}