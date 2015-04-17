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
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *p1,*p2 = head, *p3;
		if (head == NULL || k == 0 || head->next == NULL) return head;

		int list_len = k+1;
		for (int i = 0; i < k; i++) {
			if (p2->next != NULL) p2 = p2->next;
			else {list_len = i+1; break;}
		}
		if (list_len <= k) {
			int t = k % list_len;
			p2 = head;
			for (int i = 0; i < t; i++) p2 = p2->next;
		} 
		if (p2 == head) return head;
		p1 = head;
		while (p2->next != NULL) {
			p2 = p2->next; 
			p1 = p1->next;
		}
		p3 = p1->next;
		p1->next = NULL;
		p2->next = head;
		head = p3;
		return head;
    }
};

void rotateListRight_test_case1() {
	Solution solution;
	ListNode n1(1),n2(2),n3(3),n4(4),n5(5);
	n1.next=&n2; n2.next=&n3; n3.next=&n4; n4.next=&n5;
	ListNode *rl = solution.rotateRight(&n1,101);
	cout << "haha" << endl;
}

int main_rotateListRight(int argc, char **argv) {
	rotateListRight_test_case1();
	return 0;
}