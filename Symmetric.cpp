#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<iostream>
#include<math.h>

using namespace std;

//Definition for binary tree
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
    	vector<int> result_vec;
    	vector<int> pos_vec;
    	if (root == NULL) return true;
    	std::queue<int> level_queue;
    	std::queue<TreeNode *> tree_queue;
    	std::queue<int> pos_queue;
		// 1. insert root into queue
		tree_queue.push(root);
		level_queue.push(0);
		pos_queue.push(1);
		// 2. while the queue is not empty
		int last_dist = 0;
		bool is_result_symmetric = true;
		while (!tree_queue.empty() && !level_queue.empty() && !pos_queue.empty())
		{
			//3. dequeue
			TreeNode *node = tree_queue.front();
			int dist = level_queue.front();
			int pos = pos_queue.front();
			if (last_dist < dist) {
				//check whether the tow vec is symmetric
				bool is_sy = is_symm(last_dist, result_vec, pos_vec);
				if (!is_sy) return false;
				last_dist = dist;
				result_vec.clear();
				pos_vec.clear();
			}
			
			result_vec.push_back(node->val);
			pos_vec.push_back(pos);
						
			TreeNode *left = node->left;
			TreeNode *right = node->right;
			if (left != NULL) {
				tree_queue.push(left);	
				level_queue.push(dist + 1);
				pos_queue.push(pos * 2);
			}
			if (right != NULL) {
				tree_queue.push(right);
				level_queue.push(dist + 1);
				pos_queue.push(pos * 2 + 1);
			}
			tree_queue.pop();
			level_queue.pop();
			pos_queue.pop();
		}
		
		bool is_sy = is_symm(last_dist, result_vec, pos_vec);
		if (!is_sy) return false;
		
		return true;
    }
    
    bool is_symm(int dist, vector<int> &result_vec, vector<int> &pos_vec) {
    	
    	for (int j = 0; j < result_vec.size()/2; j++) 
		{
			int j_right = result_vec.size() - 1 - j;
			if (result_vec.at(j) != result_vec.at(j_right)) {
				return false;
			}
		}
    	
		vector<int> index_vec;
		int vec_len = pow(2, dist);
		for (int k = 0; k < vec_len; k++) index_vec.push_back(-1);
		
		for (int j = 0; j < pos_vec.size(); j++)
		{
			int index = pos_vec.at(j);
			int index_leave = index - vec_len;
			index_vec[index_leave] = 1;
		}
		
		for (int j = 0; j < index_vec.size()/2; j++) {
			int j_right = index_vec.size() - 1 - j;
			if (index_vec.at(j) != index_vec.at(j_right)) {
				return false;
				break;
			}
		}
		return true;
    }
};

int main(int argc, char **argv)
{
	Solution solution;
	TreeNode *node_3 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_9 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_20 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_15 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_7 = (TreeNode *)calloc(1, sizeof(TreeNode));
	
	TreeNode *node_15_1 = (TreeNode *)calloc(1, sizeof(TreeNode));
	TreeNode *node_7_1 = (TreeNode *)calloc(1, sizeof(TreeNode));
	
	node_3->val = 3; node_9->val = 9; node_20->val = 9; node_15->val = 15; node_7->val=7;
	node_15_1->val = 15; node_7_1->val = 7;
	
	node_3->left = node_9; node_3->right = node_20;
	node_20->left = node_15; node_20->right = node_7;
	node_9->left = node_7_1; node_9->right = node_15_1;
	
	bool is_symm = solution.isSymmetric(node_3);
	cout << is_symm << endl;
	
}


