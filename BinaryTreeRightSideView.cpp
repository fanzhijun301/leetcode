#include <iostream>
#include <vector>

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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res_v;
		if (root == NULL) return res_v;
		vector<TreeNode *> node_vec;
		node_vec.push_back(root);
		vector<TreeNode *> child_vec;
		while (node_vec.size() > 0) {
			for (int i=0; i < node_vec.size(); i++) {
				TreeNode *node = node_vec[i];
				if (i==node_vec.size()-1) res_v.push_back(node->val);
				if (node->left != NULL) child_vec.push_back(node->left);
				if (node->right != NULL) child_vec.push_back(node->right);
			}
			node_vec = child_vec;
			child_vec.clear();
		}
		return res_v;
    }
};

void binaryTreeRightSideView_test_case1() {
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n1.left = &n2; n1.right = &n3;
	n2.left = &n4; n2.right = &n5;
	n3.left = &n6;
	Solution solution;
	vector<int> res_v = solution.rightSideView(&n1);
	cout << res_v.size() << endl;
}

int main_binaryTreeRightSideView(int argc, char **argv) {
	binaryTreeRightSideView_test_case1();
	return 0;
}