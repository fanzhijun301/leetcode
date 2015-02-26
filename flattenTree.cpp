#include <iostream>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
		if (root == NULL) return;
		flattenTree(root);
    }

	TreeNode *flattenTree(TreeNode *node) {
		TreeNode *left = node->left;
		TreeNode *right = node->right;
		TreeNode *left_tail = NULL;
		TreeNode *right_tail = NULL;
		if (left != NULL) left_tail = flattenTree(left);
		if (right != NULL) right_tail = flattenTree(right);
		
		TreeNode *tail = NULL;
		if (left != NULL && right != NULL) {
			node->right = left;
			left_tail->right = right;
			left_tail->left = NULL;
			right->left = NULL;
			tail = right_tail;
		}
		else if (left != NULL && right == NULL) {
			node->right = left;
			tail = left_tail;
		} 
		else if (left == NULL && right != NULL){
			node->right = right;
			tail = right_tail;
		} 
		else if (left == NULL && right == NULL) {
			tail = node;
		}
		node->left = NULL;
		tail->left = NULL;

		return tail;
	}
};

void printTree(TreeNode *root) {
	while (root != NULL) {
		if (root->left != NULL) {cout << "left not null" << endl; break; }
		cout << root->val << endl;
		root = root->right;
	}
}

void flatten_test_case1() {
	TreeNode n1(1),n2(2),n3(5),n4(3),n5(4),n6(6);
	n1.left = &n2; n1.right = &n3;
	n2.left = &n4; n2.right = &n5;
	n3.right = &n6;
	Solution solution;
	solution.flatten(&n1);
	printTree(&n1);
}

int main_flattenTree(int argc, char **argv) {
	flatten_test_case1();
	return 0;
}
