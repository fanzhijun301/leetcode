#include <vector>
#include <iostream>
#include <queue>

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result_vv;
		if (root == NULL) return result_vv;

        queue<TreeNode *> traversal_queue;
		queue<int> level_queue;
		traversal_queue.push(root);
		level_queue.push(1);
		
		int last_level = 0;
		while (!traversal_queue.empty()) {
			TreeNode *top_node = traversal_queue.front();
			int curr_level = level_queue.front();

			traversal_queue.pop();
			level_queue.pop();

			if (curr_level == last_level) {
				vector<int> &in_vec = result_vv[curr_level-1];
				in_vec.push_back(top_node->val);
			} else if (curr_level > last_level) {
				vector<int> tmp_in_vec;
				result_vv.push_back(tmp_in_vec);
				vector<int> &in_vec = result_vv[curr_level-1];
				in_vec.push_back(top_node->val);
				last_level = curr_level;
			}

			if (top_node->left != NULL) {
				traversal_queue.push(top_node->left);
				level_queue.push(curr_level + 1);
			}
			if (top_node->right != NULL) {
				traversal_queue.push(top_node->right);
				level_queue.push(curr_level + 1);
			}
		}
		//reverse
		for (int i = 0; i < result_vv.size(); i++) {
			if (i % 2 == 1) {
				vector<int> &in_vec = result_vv[i];
				for (int j = 0; j < in_vec.size() / 2; j++) {
					int tmp_v = in_vec[j];
					in_vec[j] = in_vec[in_vec.size()-1-j];
					in_vec[in_vec.size()-1-j] = tmp_v;
				}
			}
		}
		return result_vv;
    }

	vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result_vv;
		if (root == NULL) return result_vv;

        queue<TreeNode *> traversal_queue;
		queue<int> level_queue;
		traversal_queue.push(root);
		level_queue.push(1);
		
		int last_level = 0;
		while (!traversal_queue.empty()) {
			TreeNode *top_node = traversal_queue.front();
			int curr_level = level_queue.front();

			traversal_queue.pop();
			level_queue.pop();

			if (curr_level == last_level) {
				vector<int> &in_vec = result_vv[curr_level-1];
				in_vec.push_back(top_node->val);
			} else if (curr_level > last_level) {
				vector<int> tmp_in_vec;
				result_vv.push_back(tmp_in_vec);
				vector<int> &in_vec = result_vv[curr_level-1];
				in_vec.push_back(top_node->val);
				last_level = curr_level;
			}

			if (top_node->left != NULL) {
				traversal_queue.push(top_node->left);
				level_queue.push(curr_level + 1);
			}
			if (top_node->right != NULL) {
				traversal_queue.push(top_node->right);
				level_queue.push(curr_level + 1);
			}
		}
		//
		for (int i = 0; i < result_vv.size() / 2; i++) {
			vector<int> tmp_v = result_vv[i];
			result_vv[i] = result_vv[result_vv.size()-1-i];
			result_vv[result_vv.size()-1-i] = tmp_v;
		}
		return result_vv;
    }
};

void zigzagLevelOrder_test_case1() {
	Solution solution;
	TreeNode n1(3),n2(9),n3(20),n4(15),n5(7);
	n1.left = &n2; n1.right = &n3;
	n3.left = &n4; n3.right = &n5;
	vector<vector<int>> result_vv = solution.zigzagLevelOrder(&n1);
	cout << result_vv.size() << endl;
}

void zigzagLevelOrder_test_case2() {
	Solution solution;
	TreeNode n1(3),n2(9),n3(20),n4(15),n5(7);
	n1.left = &n2; n1.right = &n3;
	n3.left = &n4; n3.right = &n5;
	vector<vector<int>> result_vv = solution.levelOrderBottom(&n1);
	cout << result_vv.size() << endl;
}

int main_binaryTreeZigzagle(int argc, char **argv) {
	//zigzagLevelOrder_test_case1();
	zigzagLevelOrder_test_case2();
	return 0;
}