#include<stdlib.h>
#include<stdio.h>
#include<iostream>

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
    	if (p == NULL && q == NULL) return true;
    	else if (p == NULL && q != NULL) return false;
    	else if (p != NULL && q == NULL) return false;
    	
    	bool same_value = false;
    	if (p->val == q->val) same_value = true;
    	
    	bool same_left = false;
    	if ((p->left == NULL) && (q->left == NULL)) same_left = true;
    	else if ((p->left != NULL) && (q->left != NULL)) {
    		bool same_left_tmp = isSameTree(p->left, q->left);
    		if (same_left_tmp == true) same_left = true;
    	}
    	
    	bool same_right = false;
    	if ((p->right == NULL) && (q->right == NULL)) same_right = true;
    	else if ((p->right != NULL) && (q->right != NULL)) {
    		bool same_right_tmp = isSameTree(p->right, q->right);
    		if (same_right_tmp == true) same_right = true;
    	}
		
		if (same_value && same_left && same_right) return true;
		else return false;    	
    }
};

int main(int argc, char **argv) {
	TreeNode *node_3 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_9 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_20 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_15 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_7 = (TreeNode *)calloc(1, sizeof(TreeNode));
	
	node_3->val = 3; node_9->val = 9; node_20->val = 20; node_15->val = 15; node_7->val=7;
	
	node_3->left = node_9; node_3->right = node_20;
	node_20->left = node_15; node_20->right = node_7;
	
	TreeNode *node_3_t = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_9_t = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_20_t = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_15_t = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_7_t = (TreeNode *)calloc(1, sizeof(TreeNode));
	
	node_3_t->val = 3; node_9_t->val = 9; node_20_t->val = 20; node_15_t->val = 15; node_7_t->val=7;
	
	node_3_t->left = node_9_t; node_3_t->right = node_20_t;
	node_20_t->left = node_15_t; //node_20_t->right = node_7_t;
	
	Solution solution;
	bool same = solution.isSameTree(node_3, node_3_t);
	std::cout << same << std::endl;
}
