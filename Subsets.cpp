#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets2(vector<int> &S) {
		sort(S.begin(),S.end());
		vector<vector<int>> res_v;
		if (S.size() == 0) return res_v;
		
		int size_v = S.size();
		char *sign = new char[size_v];
		for (int i = 0; i < size_v; i++) sign[i] = 0;
		int res_len = pow(2.0,size_v);
		for (int i = 0; i < res_len; i++) {
			vector<int> in_v;
			if (i > 0) for (int j = size_v - log(i*1.0) / log(2.0) - 1; j < size_v; j++) {
				char si = sign[j];
				if (si == 1) in_v.push_back(S[j]);
			}
			res_v.push_back(in_v);
			for (int j = size_v-1; j >=0; j--) {
				if (sign[j] == 1) sign[j] = 0;
				else {sign[j] = 1; break;}
			}
		}
		return res_v;
    }

	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int>> res_v;
		if (S.size() == 0) return res_v;
		sort(S.begin(), S.end());
		int size_v = S.size();
		int res_len = pow(2.0, size_v);
		int sign = 0;
		for (int i =0; i < res_len; i++) {
			vector<int> in_v;
			if (i == 0) {
				res_v.push_back(in_v);
				sign++;
				continue;
			}
			int g = pow(2.0, size_v-1);
			int j = 0;
			while (g > 0) {
				if ((sign & g) > 0) 
					in_v.push_back(S[j]);
				j++;
				g = g >> 1;
			}
			res_v.push_back(in_v);
			sign++;
		}
		return res_v;
	}

	vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
		vector<vector<int>> res_v;
		if (S.size() == 0) return res_v;
		set<string> con_set;
		set<string>::iterator it_set;

		int size_v = S.size();
		char *sign = new char[size_v];
		for (int i = 0; i < size_v; i++) sign[i] = 0;
		int res_len = pow(2.0,size_v);
		for (int i = 0; i < res_len; i++) {
			vector<int> in_v;
			if (i > 0) for (int j = size_v - log(i*1.0) / log(2.0) - 1; j < size_v; j++) {
				char si = sign[j];
				if (si == 1) in_v.push_back(S[j]);
			}
			//in_v to str
			string s_con = "";
			for (vector<int>::iterator it_v = in_v.begin(); it_v != in_v.end(); it_v++) {
				char c_i = *it_v + '0';
				s_con.append(1, c_i);
			}
			it_set = con_set.find(s_con);
			if (it_set == con_set.end()) {
				res_v.push_back(in_v);
				con_set.insert(s_con);
			}
			for (int j = size_v-1; j >=0; j--) {
				if (sign[j] == 1) sign[j] = 0;
				else {sign[j] = 1; break;}
			}
		}
		return res_v;
    }
};

void subsets_test_case1() {
	Solution solution;
	int arr[] = {1,2,3};
	vector<int> para_vec(arr, arr + sizeof(arr)/sizeof(int));
	vector<vector<int>> res_v = solution.subsets(para_vec);
	cout << res_v.size() << endl;
}

void subsets_test_case2() {
	Solution solution;
	int arr[] = {1,2,2};
	vector<int> para_vec(arr, arr + sizeof(arr)/sizeof(int));
	vector<vector<int>> res_v = solution.subsetsWithDup(para_vec);
	cout << res_v.size() << endl;
}

int main_subsets(int argc, char **argv) {
	subsets_test_case2();
	return 0;
}
