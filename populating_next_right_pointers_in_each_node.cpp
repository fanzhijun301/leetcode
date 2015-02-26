#include <iostream>

using namespace std;


/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		root->next = NULL;
		TreeLinkNode *parentNode = NULL, *headNode = root, *preNode = NULL;
		
		while (headNode != NULL) {
			parentNode = headNode;
			headNode = NULL; preNode = NULL;
			while (parentNode != NULL) {
				TreeLinkNode *left = parentNode->left;
				TreeLinkNode *right = parentNode->right;
				if (left != NULL) {
					if (preNode == NULL) {headNode = left;}
					else {preNode->next = left;}
					preNode = left;
				}
				if (right != NULL) {
					if (preNode == NULL) {headNode = right;}
					else {preNode->next = right;}
					preNode = right;
				}
				parentNode = parentNode->next;
			}
		}
    }
	
};

void connect_test_case1() {
	TreeLinkNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6),n7(7),n8(8),n9(9),n10(10),n11(11),n12(12);
	n1.left = &n2; n1.right = &n3;
	n2.left = &n4; n2.right = &n5;
	n3.left = &n6; n3.right = &n7;
	n4.left = &n8;
	n5.right = &n9;
	n6.right = &n10;
	n7.left = &n11; n7.right = &n12;

	Solution solution;
	solution.connect(&n1);

}

int main_connect(int argc, char **argv) {
	connect_test_case1();
	return 0;
}