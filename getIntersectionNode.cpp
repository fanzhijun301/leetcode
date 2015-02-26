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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int len_a = 1, len_b = 1;
		ListNode *nodeA = headA, *nodeB = headB;
		if (nodeA == NULL || nodeB == NULL) return NULL;
		while (nodeA->next != NULL) {nodeA = nodeA->next; len_a++;}
		while (nodeB->next != NULL) {nodeB = nodeB->next; len_b++;}
		if (nodeA != nodeB) return NULL;
		
		nodeA = headA; nodeB = headB;
		int diff = (len_a > len_b)?len_a-len_b:len_b-len_a;
		if (len_a > len_b) for (int i = 0; i < diff; i++) nodeA = nodeA->next; 
		else if (len_a < len_b) for (int i = 0; i < diff; i++) nodeB = nodeB->next;

		while (nodeA != nodeB) {
			nodeA = nodeA->next;
			nodeB = nodeB->next;
		}
		return nodeA;
    }
};

void getIntersectionNode_test_case1() {
	ListNode *headA;
	ListNode *headB;

	ListNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6),n7(7),n8(8);
	n1.next = &n2; n2.next=&n6; n6.next=&n7;n7.next=&n8; n8.next=NULL;
	n3.next=&n4; n4.next=&n5; n5.next=&n6;

	headA = &n1; headB = &n3;

	Solution solution;
	ListNode *interNode = solution.getIntersectionNode(headA, headB);
	if (interNode == NULL) {
		cout << "NULL" << endl;
	} else {
		cout << interNode->val << endl;
	}
}

int main_getIntersectionNode(int argc, char **argv) {
	getIntersectionNode_test_case1();
	return 0;
}