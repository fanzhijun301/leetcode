#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> r_vec;
		if (root == NULL) return r_vec;
		stack<TreeNode *> travers_stack;
		travers_stack.push(root);
		bool is_push = true;

		while (!travers_stack.empty()) {
			TreeNode *top = travers_stack.top();
			if (top->left != NULL && is_push) travers_stack.push(top->left);
			else {
				travers_stack.pop();
				r_vec.push_back(top->val);
				is_push = false;
				if (top->right != NULL) {travers_stack.push(top->right); is_push = true;}
			}
		}
		return r_vec;
    }
};

void inorderTraversal_test_case1() {
	TreeNode n4(4),n2(2),n5(5),n1(1),n3(3),n7(7);
	n4.left = &n2; n4.right = &n5;
	n2.left = &n1; n2.right = &n3;
	n5.right = &n7;

	Solution solution;
	vector<int> r_vec = solution.inorderTraversal(&n4);
	cout << r_vec.size() << endl;
}

int main(int argc, char **argv) {
	inorderTraversal_test_case1();
	return 0;
}