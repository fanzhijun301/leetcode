#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res_v;
		int total_len = s.size();
		char *arr = new char[total_len];
		for (int i = 0; i < total_len; i++) {
			arr[i] = s[i] - '0';
		}
		int p1=0,p2=1,p3=2;
		
		return res_v;
    }
};

void restoreIpAddresses_test_case1() {
	Solution solution;
	string s = "25525511135";
	vector<string> res_v = solution.restoreIpAddresses(s);
	cout << res_v.size() << endl;
}

int main_restoreIpAddresses(int argc, char **argv) {
	restoreIpAddresses_test_case1();
	return 0;
}