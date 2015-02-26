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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> pre_vec;
        bool push_pop = true; //push:true pop:false
        stack<TreeNode *> pre_stack;
        stack<int> is_parent_stack;
        if (root == NULL) return pre_vec;
        pre_stack.push(root);
        is_parent_stack.push(1);
        while (!pre_stack.empty() && !is_parent_stack.empty()) {
        	TreeNode *node = pre_stack.top();
        	int is_parent = is_parent_stack.top();
        	
        	if (is_parent == 0) {
        		pre_vec.push_back(node->val);
        		pre_stack.pop(); 
        		is_parent_stack.pop();
        		continue;
        	}
        	TreeNode *left = node->left;
        	TreeNode *right = node->right;
        	if ((left != NULL) || (right != NULL)) {
        		is_parent_stack.top() = 0;
        	}
        	if (right != NULL) {
        		pre_stack.push(right);
        		is_parent_stack.push(1);
        	} 
        	if (left != NULL) {
        		pre_stack.push(left);
        		is_parent_stack.push(1);
        	}
        	if ((left == NULL) && (right == NULL)) {
        		pre_vec.push_back(node->val);
        		pre_stack.pop();
        		is_parent_stack.pop();
        	}
        }
        return pre_vec;
    }
};

TreeNode *init_tree_1() {
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
	return node_3;
}

TreeNode *init_tree_2() {
	TreeNode *node_2 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_1 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_4 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_3 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_5 = (TreeNode *)calloc(1, sizeof(TreeNode));
	
	node_2->val = 2; node_1->val = 1; node_3->val = 3; node_4->val = 4; node_5->val = 5;
	
	node_2->left = node_1; node_1->left = node_3; 
	node_2->right = node_4; node_4->left = node_5;
	
	node_1->right = NULL; node_3->left = NULL; node_3->right = NULL;
	node_4->right = NULL; node_5->left = NULL; node_5->right = NULL;
	
	return node_2;
}

int main(int argc, char **argv) {
	Solution solution;
	
	TreeNode *node_2 = init_tree_2();
	vector<int> pre_vec = solution.postorderTraversal(node_2);
	vector<int>::iterator it;
	for (it = pre_vec.begin(); it != pre_vec.end(); it++) {
		cout << *it << endl;
	}
}
