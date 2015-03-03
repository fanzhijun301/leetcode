#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
		int len_s = S.size() + 1;
		int len_t = T.size() + 1;

		int *matrix = new int[len_s * len_t];
		for (int i = 0; i < len_s; i++) matrix[0 * len_s + i] = 1;
		for (int i = 1; i < len_t; i++) matrix[i * len_s + 0] = 0;
		
		for (int i = 1; i < len_t; i++) {
			char c_t = T.at(i-1);
			for (int j = 1; j < len_s; j++) {
				char s_t = S.at(j-1);
				if (c_t == s_t) matrix[i * len_s + j] = matrix[(i-1)*len_s + j - 1] + matrix[i*len_s + j-1];
				else matrix[i*len_s+j] = matrix[i*len_s+j-1];
			}
		}
		return matrix[(len_t-1) * len_s + len_s - 1];
    }
};

void numDistinct_test_case1() {
	string s = "abac";
	string t = "ac";
	Solution solution;
	int n = solution.numDistinct(s, t);
	cout << n << endl;
}

int main(int argc, char **argv) {
	numDistinct_test_case1();
	return 0;
}