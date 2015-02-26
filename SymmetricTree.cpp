#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

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
    bool isSymmetric(TreeNode *root) {
        
    }
    
    void levelOrder(TreeNode *root, vector<vector<int> > &level_order_vec, vector<vector<int> > &level_pos_vec) {
    	if (root == NULL) return;
    	std::queue<int> level_queue;
    	std::queue<TreeNode *> tree_queue;
		// 1. insert root into queue
		tree_queue.push(root);
		level_queue.push(0);
		// 2. while the queue is not empty
		while (!tree_queue.empty() && !level_queue.empty())
		{
			//3. dequeue
			TreeNode *node = tree_queue.front();
			int dist = level_queue.front();
			if (level_order_vec.size() < dist + 1) {
				vector<int> in_vec;
				level_order_vec.push_back(in_vec);
			}
			vector<int> &in_vec = level_order_vec.at(dist);
			in_vec.push_back(node->val);
						
			TreeNode *left = node->left;
			TreeNode *right = node->right;
			if (left != NULL) {
				tree_queue.push(left);	
				level_queue.push(dist + 1);
			}
			if (right != NULL) {
				tree_queue.push(right);
				level_queue.push(dist + 1);
			}
			tree_queue.pop();
			level_queue.pop();
		}
    }
};
