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
    bool isSymmetric(TreeNode *root) {
		if (root == NULL) return true;
		if (root->left==NULL && root->right==NULL) return true;
		vector<TreeNode *> first_vec;
		vector<TreeNode *>::iterator it_vec;
		first_vec.push_back(root);
		int last_vec_size = 1;
		while (first_vec.size() > 0) {
			vector<TreeNode *> second_vec(last_vec_size * 2, NULL);
			int not_null_count = 0, second_index = 0;
			for (int i = 0; i < first_vec.size(); i++) {
				TreeNode *node = first_vec[i];
				if (node == NULL) continue;
				second_vec[second_index++] = node->left;
				second_vec[second_index++] = node->right;
				if (node->left != NULL) not_null_count++;
				if (node->right != NULL) not_null_count++;
			}
			last_vec_size = not_null_count;
			//see second_vec is symmetric
			for (int i = 0; i < second_vec.size()/2; i++) {
				TreeNode *first = second_vec[i];
				TreeNode *second = second_vec[second_vec.size()-1-i];
				if (first == NULL && second != NULL) return false;
				else if (first != NULL && second == NULL) return false;
				else if (first != NULL && second != NULL && first->val != second->val) return false;
			}
			first_vec = second_vec;
		}
		return true;
    }
};

void symmetricTree_test_case1() {
	Solution solution;
	TreeNode n1(1),n21(2),n22(2),n31(3),n32(4),n33(4),n34(3);
	n1.left=&n21; n1.right=&n22;
	n21.left=&n31; //n21.right=&n32; n22.left=&n33; 
	n22.right=&n34;
	bool is_semm = solution.isSymmetric(&n1);
	cout << is_semm << endl;
}

int main_symmetric(int argc, char **argv) {
	symmetricTree_test_case1();
	return 0;
}