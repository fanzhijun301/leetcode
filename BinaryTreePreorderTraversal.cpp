#include<vector>
#include<stack>
#include<iostream>
#include<stdlib.h>

using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> pre_vec;
        stack<TreeNode *> pre_stack;
        if (root == NULL) return pre_vec;
        pre_stack.push(root);
        while (!pre_stack.empty()) {
        	TreeNode *node = pre_stack.top();
        	pre_vec.push_back(node->val);
        	pre_stack.pop();
        	TreeNode *left = node->left;
        	TreeNode *right = node->right;
        	if (right != NULL) {
        		pre_stack.push(right);
        	} 
        	if (left != NULL) {
        		pre_stack.push(left);
        	}
        }
        return pre_vec;
    }
};

int main(int argc, char **argv) {
	Solution solution;
	TreeNode *node_3 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_9 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_20 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_15 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_7 = (TreeNode *)calloc(1, sizeof(TreeNode));
	
	node_3->val = 3; node_9->val = 9; node_20->val = 20; node_15->val = 15; node_7->val=7;
	
	node_3->left = node_9; node_3->right = node_20;
	node_20->left = node_15; node_20->right = node_7;
	
	node_9->left = NULL; node_9->right = NULL;
	node_15->left = NULL; node_15->right = NULL;
	node_7->left = NULL; node_7->right = NULL;
	
	vector<int> pre_vec = solution.preorderTraversal(node_3);
	vector<int>::iterator it;
	for (it = pre_vec.begin(); it != pre_vec.end(); it++) {
		cout << *it << endl;
	}
}
