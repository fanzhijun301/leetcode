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
    bool isBalanced(TreeNode *root) {
		int depth = 0;
		bool balanced = nodeBalanced(root, &depth);
		return balanced;
    }

	bool nodeBalanced(TreeNode *node, int *depth) {
		bool left_balanced = true,right_balanced = true;
		int left_depth = 0, right_depth = 0;
		if (node->left != NULL) left_balanced = nodeBalanced(node->left, &left_depth);
		if (node->right != NULL) right_balanced = nodeBalanced(node->right, &right_depth);

		if (node->left == NULL && node->right == NULL) *depth = 1;
		else {
			*depth = (left_depth > right_depth) ? left_depth : right_depth;
			(*depth)++;
		}
		
		if (!left_balanced || !right_balanced) return false;
		
		if (abs(left_depth - right_depth) > 1) return false;
		else return true;
	}
};

void isBalanced_test_case1() {
	TreeNode n1(1),n2(2),n3(2),n4(3),n5(3),n6(4),n7(4),n8(5);
	n1.left=&n2;n1.right=&n3;
	n2.left=&n4;n2.right=&n5;
	n3.left=&n8;
	n4.left=&n6;n4.right=&n7;

	Solution solution;
	bool balanced = solution.isBalanced(&n1);
	cout << balanced << endl;
}

int main_isBalanced(int argc, char **argv) {
	isBalanced_test_case1();
	return 0;
}