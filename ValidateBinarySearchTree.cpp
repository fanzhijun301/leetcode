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
    bool isValidBST(TreeNode *root) {
		if (root == NULL) return true;
		if (root->left == NULL && root->right == NULL) return true;
        TreeNode *pre_node = NULL;
		return middle_order(root, pre_node);
    }

	bool middle_order(TreeNode *node, TreeNode *&pre_node) {
		bool left_valid = true;
		if (node->left != NULL) left_valid = middle_order(node->left, pre_node);
		if (!left_valid) return false;
		if (pre_node != NULL) {
			if (pre_node->val >= node->val) return false;
		}
		pre_node = node;
		bool right_valid = true;
		if (node->right != NULL) right_valid = middle_order(node->right, pre_node);
		if (!right_valid) return false;
		return left_valid && right_valid;
	}
};

void validateBinarySearchTree_test_case1() {
	TreeNode n4(4),n2(2),n5(7),n1(1),n3(3),n7(5);
	n4.left = &n2; n4.right = &n5;
	n2.left = &n1; n2.right = &n3;
	n5.right = &n7;

	Solution solution;
	bool is_valid = solution.isValidBST(&n4);
	cout << is_valid << endl;
}

void validateBinarySearchTree_test_case2() {
	TreeNode n1(1),n2(1);
	n1.left = &n2;

	Solution solution;
	bool is_valid = solution.isValidBST(&n1);
	cout << is_valid << endl;
}

int main_validateBinarySearchTree(int argc, char **argv) {
	validateBinarySearchTree_test_case2();
	return 0;
} 