#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result_vv;
		if (num.size() == 0) return result_vv;
		int result_len = 1;
		int vec_len = num.size();
		for (int i = 2; i <= vec_len; i++) result_len *= i;
		result_vv.resize(result_len);
		vector<int> res_in_vec(vec_len, 0);

		for (int i = 0; i < result_len; i++) result_vv[i] = res_in_vec;
		for (int i = 0; i < num.size(); i++) result_vv[0][i] = num[i];
		for (int len = 2; len <= vec_len; len++) {
			int add_num = num[len-1];
			int past_vec_len = 1;
			for (int i=1; i<=len-1;i++)past_vec_len *= i;
			int insert_idx = past_vec_len;
			for (int past_idx = 0; past_idx < past_vec_len; past_idx++) {
				vector<int> &last_in_vec = result_vv[past_idx];
				for (int in_idx = 0; in_idx < len-1; in_idx++) {
					vector<int> &insert_vec = result_vv[insert_idx];
					bool has_insert = false;
					for (int copy_idx = 0; copy_idx < len; copy_idx++) {
						if (copy_idx == in_idx) {
							insert_vec[copy_idx] = add_num;
							has_insert = true;
						}
						else if (!has_insert) insert_vec[copy_idx] = last_in_vec[copy_idx];
						else insert_vec[copy_idx] = last_in_vec[copy_idx-1];
					}
					for (int copy_idx = len; copy_idx < vec_len; copy_idx++) {
						insert_vec[copy_idx] = last_in_vec[copy_idx];
					}
					insert_idx++;
				}
			}
		}
		return result_vv;
    }
};

void premute_test_case1() {
	Solution solution;
	vector<int> para_vec;
	para_vec.push_back(1); para_vec.push_back(2); para_vec.push_back(3);
	para_vec.push_back(4);
	vector<vector<int>> result_vv = solution.permute(para_vec);
	cout << result_vv.size() << endl;
}

int main_premutations(int argc, char **argv) {
	premute_test_case1();
	return 0;
}