#include <iostream>
#include <vector>

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
    TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.size() == 0) return NULL;
		TreeNode *root = buildTree_pre_in(preorder, inorder, 0, 0, inorder.size()-1);
		return root;
    }

	TreeNode *buildTree_pre_in(vector<int> &preorder, vector<int> &inorder, 
		int pre, int begin, int end) {
		
		TreeNode *node = new TreeNode(preorder[pre]);
		int middle = -1;
		for (int i = begin; i <= end; i++) {
			if (preorder[pre] == inorder[i]) {middle = i; break;}
		}
		if (middle > begin) {
			TreeNode *left = buildTree_pre_in(preorder, inorder, pre+1, begin, middle-1);
			node->left = left;
		}		
		if (middle < end) {
			int pre_right = pre + middle - begin + 1;
			TreeNode *right = buildTree_pre_in(preorder, inorder, pre_right, middle + 1, end);
			node->right = right;
		}

		return node;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (postorder.size() == 0) return NULL;
		TreeNode *root = buildTree_in_post(inorder, postorder, postorder.size()-1, 0, inorder.size()-1);
		return root;
    }

	TreeNode *buildTree_in_post(vector<int> &inorder, vector<int> &postorder, 
		int post, int begin, int end) {
		
		TreeNode *node = new TreeNode(postorder[post]);
		int middle = -1;
		for (int i = 0; i < inorder.size(); i++) {
			if (inorder[i] == postorder[post]) {middle = i; break;}
		}
		if (middle > begin) {
			int new_post = post - (end-middle + 1);
			TreeNode *left = buildTree_in_post(inorder, postorder, new_post, begin, middle-1);
			node->left = left;
		}
		if (middle < end) {
			TreeNode *right = buildTree_in_post(inorder, postorder, post-1, middle+1,end);
			node->right = right;
		}
		return node;
	}
};

void pre_inorder_buildTree_test_case1() {
	Solution solution;
	int pre_arr[] = {1,2,4,5,3,6,7};
	int in_arr[] = {4,2,5,1,6,3,7};
	int post_arr[] = {4,5,2,6,7,3,1};
	vector<int> pre_vec(pre_arr, pre_arr + 7);
	vector<int> in_vec(in_arr, in_arr + 7);
	vector<int> post_vec(post_arr, post_arr + 7);

	TreeNode *root = solution.buildTree(in_vec, post_vec);
	cout << root->val << endl;
}

void pre_inorder_buildTree_test_case2() {
	Solution solution;
	int pre_arr[] = {1,2,3,4,5};
	int in_arr[] = {2,1,3,4,5};
	int post_arr[] = {2,5,4,3,1};
	vector<int> pre_vec(pre_arr, pre_arr + 5);
	vector<int> in_vec(in_arr, in_arr + 5);
	vector<int> post_vec(post_arr, post_arr + 5);

	TreeNode *root = solution.buildTree(in_vec, post_vec);
	cout << root->val << endl;
}

void pre_inorder_buildTree_test_case3() {
	Solution solution;
	int pre_arr[] = {1,2,3,4,5};
	int in_arr[] = {2,1,5,4,3};
	int post_arr[] = {2,5,4,3,1};
	vector<int> pre_vec(pre_arr, pre_arr + 5);
	vector<int> in_vec(in_arr, in_arr + 5);
	vector<int> post_vec(post_arr, post_arr + 5);

	TreeNode *root = solution.buildTree(in_vec, post_vec);
	cout << root->val << endl;
}

int main_construct_binary(int argc, char **argv) {
	pre_inorder_buildTree_test_case1();
	pre_inorder_buildTree_test_case2();
	pre_inorder_buildTree_test_case3();
	return 0;
}