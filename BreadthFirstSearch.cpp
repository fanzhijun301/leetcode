#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<queue>

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
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > result_vec;
    	if (root == NULL) return result_vec;
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
			if (result_vec.size() < dist + 1) {
				vector<int> in_vec;
				result_vec.push_back(in_vec);
			}
			vector<int> &in_vec = result_vec.at(dist);
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
		return result_vec;
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
	
	node_3->val = 3; node_9->val = 9; node_20->val = 20; node_15->val = 15; node_7->val=7;
	
	node_3->left = node_9; node_3->right = node_20;
	node_20->left = node_15; node_20->right = node_7;
	
	vector<vector<int> > result_vec = solution.levelOrder(node_3);
	
	for (int i = 0; i < result_vec.size(); i++) 
	{
		vector<int> in_vec = result_vec.at(i);
		for (int j = 0; j < in_vec.size(); j++) 
		{
			printf("%d ", in_vec.at(j));
		}
		printf("\n");
	}
}


