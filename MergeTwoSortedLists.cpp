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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
		else if (l2 == NULL) return l1;
	
		ListNode *head, *last_tail;
		int first_second = 0;
		if (l1->val < l2->val) { head = l1; l1 = l1->next; first_second = 1;} 
		else { head = l2; l2 = l2->next; first_second = 2;}
		last_tail = head;

		while (l1 != NULL && l2 != NULL) {
			if (first_second ==1) {
				if (l1->val < l2->val) {last_tail = l1; l1 = l1->next;}
				else {
					ListNode *tmp = l2->next;
					last_tail->next = l2; 
					l2->next = l1;
					last_tail = l2;
					l2 = tmp;
				}
			} else if (first_second == 2) {
				if (l2->val < l1->val) {last_tail = l2; l2 = l2->next;}
				else {
					ListNode *tmp = l1->next;
					last_tail->next = l1;
					l1->next = l2;
					last_tail = l1;
					l1 = tmp;
				}
			}
		}
		if (l1 == NULL) last_tail->next = l2;
		else if (l2 == NULL) last_tail->next = l1;
		return head;
    }
};

void mergeTwoLists_test_case1() {
	Solution solution;
	ListNode n1(1),n3(3),n5(5),n7(7);
	ListNode n2(2),n4(4),n6(6);
	n1.next = &n3; n3.next = &n5; n5.next = &n7;
	n2.next = &n4; n4.next = &n6;
	ListNode *merge = solution.mergeTwoLists(&n1,&n2);
	cout << "haha" << endl;
}

void mergeTwoLists_test_case2() {
	Solution solution;
	ListNode n1(1),n2(1);
	ListNode *merge = solution.mergeTwoLists(&n1,&n2);
	cout << "haha" << endl;
}

int main_mergeTwoSortedLists(int argc, char **argv) {
	mergeTwoLists_test_case1();
	mergeTwoLists_test_case2();
	return 0;
}