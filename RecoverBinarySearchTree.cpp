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
    void recoverTree(TreeNode *root) {
		if (root == NULL) return;
		if (root->left == NULL && root->right == NULL) return;
		vector<TreeNode *> node_vec;
		TreeNode *pre_node = NULL;
        deep_first(root, node_vec, pre_node);
		if (node_vec.size() > 0) {
			TreeNode *first = node_vec[0];
			TreeNode *last = node_vec[node_vec.size()-1];
			int tmp = first->val;
			first->val = last->val;
			last->val = tmp;
		}
    }

	void deep_first(TreeNode *node, vector<TreeNode *> &node_vec, TreeNode *&pre_node) {
		
		if (node->left != NULL) deep_first(node->left, node_vec, pre_node);
		if (pre_node != NULL)
		{
			if (pre_node->val > node->val) {
				node_vec.push_back(pre_node);
				node_vec.push_back(node);
			}
		}
		pre_node = node;
		if (node->right != NULL) deep_first(node->right, node_vec, pre_node);
	}
};

void recoverBinarySearchTree_middle_print(TreeNode *root) {
	if (root->left != NULL) recoverBinarySearchTree_middle_print(root->left);
	printf("%d\n",root->val);
	if (root->right != NULL) recoverBinarySearchTree_middle_print(root->right);
}

void recoverBinarySearchTree_test_case1() {
	TreeNode n4(7),n2(2),n5(5),n1(1),n3(3),n7(4);
	n4.left = &n2; n4.right = &n5;
	n2.left = &n1; n2.right = &n3;
	n5.right = &n7;

	Solution solution;
	solution.recoverTree(&n4);
	recoverBinarySearchTree_middle_print(&n4);
	cout << "aaha" << endl;
}

int main_recoverBinarySearchTree(int argc, char **argv) {
	recoverBinarySearchTree_test_case1();
	return 0;
}