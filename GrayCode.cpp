#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
		vector<int> result_vec;
		if (n == 0) {
			result_vec.push_back(0);
			return result_vec;
		}
        vector<string> in_vec;
		int vec_len = pow(2.0f,n);
		in_vec.resize(vec_len);
		in_vec[0] = "0";
		in_vec[1] = "1";

		for (int i = 2; i <=n; i++) {
			int pre = pow(2.0f,i-1);
			int len = pow(2.0f,i);
			for (int j = pre-1; j >=0; j--) {
				int back = len-1-j;
				in_vec[back] = "1" + in_vec[j];
				in_vec[j] = "0" + in_vec[j];
			}
		}
		result_vec.resize(vec_len);
		for (int i = 0; i < in_vec.size(); i++) {
			int num = 0;
			string s = in_vec[i];
			for (int j = 0; j < s.size(); j++) {
				char c = s[n-j-1];
				num += pow(2.0f,j) * (c-'0');
			}
			result_vec[i] = num;
		}
		return result_vec;
    }
};

void grayCode_test_case1() {
	Solution solution;
	vector<int> result_vec = solution.grayCode(1);
	cout << result_vec.size() << endl;
}

int main_gray_code(int argc, char **argv) {
	grayCode_test_case1();
	return 0;
}