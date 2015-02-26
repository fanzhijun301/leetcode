#include <vector>
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > path_vec;
		if (root != NULL) path_vec = pathSum(root, sum, 0);
		return path_vec;
    }

	vector<vector<int> > pathSum(TreeNode *node, int sum, int current) {
		vector<vector<int> > left_path_vec, right_path_vec;
		if (node->left != NULL) left_path_vec = pathSum(node->left, sum, current + node->val);
		if (node->right != NULL) right_path_vec = pathSum(node->right, sum, current + node->val);

		if (node->left == NULL && node->right == NULL) {
			if (sum == current + node->val) {
				vector<int> in_vec;
				in_vec.push_back(node->val);
				left_path_vec.push_back(in_vec);
				return left_path_vec;
			}
		}

		for (int i = 0; i < right_path_vec.size(); i++) {
			left_path_vec.push_back(right_path_vec.at(i));
		}

		for (int i = 0; i < left_path_vec.size(); i++) {
			vector<int> &in_vec = left_path_vec.at(i);
			vector<int>::iterator it_vec=in_vec.begin();
			in_vec.insert(it_vec, node->val);
		}

		return left_path_vec;
	}

	bool hasPathSum(TreeNode *root, int sum) {
		bool has_path = hasPathSum(root, sum, 0);
		return has_path;
	}

	bool hasPathSum(TreeNode *node, int sum, int current) {
		bool left_has = false, right_has = false;
		if (node->left != NULL) left_has = hasPathSum(node->left, sum, current + node->val);
		if (node->right != NULL) right_has = hasPathSum(node->right, sum, current + node->val);

		if (left_has || right_has) return true;

		if (node->left == NULL && node->right == NULL) {
			if (sum == current + node->val) return true;
		}
		return false;
	}
};

void pathSum_test_case1() {
	TreeNode n1(5),n2(4),n3(8),n4(11),n5(13),n6(4),n7(7),n8(2),n9(5),n10(1);
	n1.left=&n2; n1.right=&n3;
	n2.left=&n4; 
	n3.left=&n5; n3.right=&n6;
	n4.left=&n7; n4.right=&n8;
	n6.left=&n9; n6.right=&n10;
	Solution solution;
	
	vector<vector<int> > rvv = solution.pathSum(&n1, 22);
	vector<vector<int> >::iterator it_vv;
	vector<int>::iterator it_v;
	for (it_vv = rvv.begin(); it_vv != rvv.end(); it_vv++) {
		vector<int> rv = *it_vv;
		for (it_v = rv.begin(); it_v != rv.end(); it_v++) {
			cout << *it_v << " ";
		}
		cout << endl;
	}
	//bool has_path = solution.hasPathSum(&n1, 22);
	//cout << has_path << endl;
}

int main_pathSum(int argc, char **argv) {
	pathSum_test_case1();
	return 0;
}