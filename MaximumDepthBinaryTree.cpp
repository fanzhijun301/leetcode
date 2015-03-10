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
    int maxDepth(TreeNode *root) {
		if (root == NULL) return 0;
        int curr_depth = 1, max_depth = 1;
		deep_first(root, curr_depth, &max_depth);
		return max_depth;
    }

	void deep_first(TreeNode *node, int curr_depth, int *max_depth) {
		if (curr_depth > *max_depth) *max_depth = curr_depth;
		if (node->left != NULL) deep_first(node->left, curr_depth + 1, max_depth);
		if (node->right != NULL) deep_first(node->right, curr_depth + 1, max_depth);
	}
};

void maxDepth_test_case1() {
	Solution solution;
	TreeNode n1(3),n2(9),n3(20),n4(15),n5(7);
	n1.left = &n2; n1.right = &n3;
	n3.left = &n4; n3.right = &n5;

	int max_depth = solution.maxDepth(&n1);
	cout << max_depth << endl;
}

int main_maxDepth(int argc, char **argv) {
	maxDepth_test_case1();
	return 0;
}
