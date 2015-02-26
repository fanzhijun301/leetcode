#include<string>
#include<vector>
#include<limits.h>
#include<iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int max_len = 1;
		int left_pos = 0;
		int right_pos = 0;
    	for (int i = 0; i < s.length(); i++) {
			int left_index = i;
			int right_index = i;
			int len = 0;
			while (left_index >= 0 && right_index < s.length()) {
				char c_l = s.at(left_index);
				char c_r = s.at(right_index);
				if (c_l == c_r) {
					len += right_index - left_index + 1;
					left_index -= 1;
					right_index += 1;
				} else break;
			}
			if (len > max_len) {
				max_len = len;
				left_pos = left_index + 1;
				right_pos = right_index - 1;
			}

			len = 0;
			left_index = i;
			right_index = i + 1;
			while (left_index >= 0 && right_index < s.length()) {
				char c_l = s.at(left_index);
				char c_r = s.at(right_index);
				if (c_l == c_r) {
					len += right_index - left_index + 1;
					left_index -= 1;
					right_index += 1;
				} else break;
			}
			if (len > max_len) {
				max_len = len;
				left_pos = left_index + 1;
				right_pos = right_index - 1;
			}
		}  
		//cout << left_pos << "," << right_pos << endl;
		return s.substr(left_pos, right_pos - left_pos + 1);
    }
};

int main(int argc, char **argv) {
	Solution solution;
	string s = "bk";
	string r = solution.longestPalindrome(s);
	cout << r << endl;
}

