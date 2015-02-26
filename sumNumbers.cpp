#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>

using namespace std;

/**
 * Definition for binary tree
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	
	void sum_rec(TreeNode *node, vector<int> &root_leaf_vec, int &sum) {
		int val = node->val;
		root_leaf_vec.push_back(val);
		
		if (node->left == NULL && node->right == NULL) {
			for (int i = 0; i < root_leaf_vec.size(); i++) {
				int v = root_leaf_vec.at(i);
//				cout << v;
				sum += v * pow(10, root_leaf_vec.size() - 1 - i);
			}
//			cout << endl;
		} else {
			if (node->left != NULL) {
				sum_rec(node->left, root_leaf_vec, sum);
			}
			if (node->right != NULL) {
				sum_rec(node->right, root_leaf_vec, sum);
			}
		}
		root_leaf_vec.erase(root_leaf_vec.end() - 1);
	}
	
    int sumNumbers(TreeNode *root) {
    	if (root == NULL) return 0;
        vector<int> root_leaf_vec;
        int sum = 0;
        sum_rec(root, root_leaf_vec, sum);
        return sum;
    }
};

TreeNode *init_tree_1() {
	TreeNode *node_3 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_9 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_2 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_5 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_7 = (TreeNode *)calloc(1, sizeof(TreeNode));
	
	node_3->val = 3; node_9->val = 9; node_2->val = 2; node_5->val = 5; node_7->val=7;
	
	node_3->left = node_9; node_3->right = node_2;
	node_2->left = node_5; node_2->right = node_7;
	
	node_9->left = NULL; node_9->right = NULL;
	node_5->left = NULL; node_5->right = NULL;
	node_7->left = NULL; node_7->right = NULL;
	return node_3;
}

TreeNode *init_tree_2() {
	TreeNode *node_4 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_9 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_0 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_1 = (TreeNode *)calloc(1, sizeof(TreeNode));
	
	node_4->val=4; node_9->val=9; node_0->val=0; node_1->val=1;
	node_4->left=node_9; node_4->right=node_0;
	node_9->left=NULL; node_9->right=node_1;
	node_0->left=NULL; node_0->right=NULL;
	node_1->left=NULL; node_1->right=NULL;
	
	return node_4;
}

int main(int argc, char **argv) {
	Solution solution;
	TreeNode *root = init_tree_2();
	int sum = solution.sumNumbers(root);
	cout << sum << endl;
}
