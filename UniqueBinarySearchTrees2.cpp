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
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<TreeNode *> > trees_vec_vec;
		vector<TreeNode *> tree_vec;
		TreeNode *node_t = NULL;
		tree_vec.push_back(node_t);
		trees_vec_vec.push_back(tree_vec);
		if (n == 0) return tree_vec;

		TreeNode *node = new TreeNode(1);
		vector<TreeNode *> tree_vec_1;
		tree_vec_1.push_back(node);
		trees_vec_vec.push_back(tree_vec_1);
		if (n == 1) return tree_vec_1;

		for (int node_num = 2; node_num <= n; node_num++) {
			vector<TreeNode *> new_vec;
			for (int left = 0; left < node_num; left++) {
				int right = node_num - 1 - left;

				vector<TreeNode *> left_trees = trees_vec_vec.at(left);
				vector<TreeNode *> right_trees = trees_vec_vec.at(right);
				if (left_trees.size() == 0) {
					for (int i = 0; i < right_trees.size(); i++) {
						TreeNode *old_right = right_trees.at(i);
						TreeNode *new_right = NULL;
						if (old_right != NULL) new_right = copyTree(old_right);

						TreeNode *new_root = new TreeNode(1);
						new_root->right = new_right;
						new_vec.push_back(new_root);
					}
					continue;
				}
				if (right_trees.size() == 0) {
					for (int i = 0; i < left_trees.size(); i++) {
						TreeNode *old_left = left_trees.at(i);
						TreeNode *new_left = NULL;
						if (old_left != NULL) new_left = copyTree(old_left);

						TreeNode *new_root = new TreeNode(1);
						new_root->left = new_left;
						new_vec.push_back(new_root);
					}
				}

				for (int i = 0; i < left_trees.size(); i++) {
					TreeNode *old_left = left_trees.at(i);
					TreeNode *new_left = NULL;
					if (old_left != NULL) new_left = copyTree(old_left);
					for(int j = 0; j < right_trees.size(); j++) {
						TreeNode *old_right = right_trees.at(j);
						TreeNode *new_right = NULL;
						if (old_right != NULL)new_right = copyTree(old_right);
						
						TreeNode *new_root = new TreeNode(1);
						new_root->left = new_left;
						new_root->right = new_right;

						new_vec.push_back(new_root);
					}
				}
			}
			trees_vec_vec.push_back(new_vec);
		}
		
		vector<TreeNode *> last_vec = trees_vec_vec.at(trees_vec_vec.size() - 1);
		vector<TreeNode *>::iterator it_vec;
		for (it_vec = last_vec.begin(); it_vec != last_vec.end(); it_vec++) {
			TreeNode *node = *it_vec;
			setNodesValue(node);
		}
		return last_vec;
    }

	TreeNode *copyTree(TreeNode *node) {
		TreeNode *new_node = new TreeNode(node->val);
		if (node->left != NULL) new_node->left = copyTree(node->left);
		if (node->right != NULL) new_node->right = copyTree(node->right);
		return new_node;
	}

	void setNodesValue(TreeNode *node) {
		stack<TreeNode *> parentStack;
		TreeNode *nodep = node;
		while (nodep != NULL) {
			parentStack.push(nodep);
			nodep = nodep->left;
		}
		int value = 1;
		while (!parentStack.empty()) {
			TreeNode *topNode = parentStack.top();
			topNode->val = value;
			value++;
			parentStack.pop();
			if (topNode->right != NULL) {
				nodep = topNode->right;
				while (nodep != NULL) {
					parentStack.push(nodep);
					nodep = nodep->left;
				}
			}
		}
	}
};

void generateTrees_test_case1() {
	Solution solution;
	vector<TreeNode *> trees_vec = solution.generateTrees(10);
	cout << trees_vec.size() << endl;
}

int main(int argc, char **argv) {
	generateTrees_test_case1();
	return 0;
}