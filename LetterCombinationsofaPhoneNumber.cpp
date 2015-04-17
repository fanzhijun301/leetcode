#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		map<char, string> digit_map;
		digit_map['2'] = "abc"; digit_map['3'] = "def"; digit_map['4'] = "ghi";
		digit_map['5'] = "jkl"; digit_map['6'] = "mno"; digit_map['7'] = "pqrs";
		digit_map['8'] = "tuv"; digit_map['9'] = "wxyz";

        vector<string> first_vec;
		if (digits.size()==0) return first_vec;

		vector<string>::iterator it_vec;
		char c1 = digits[0];
		string s1 = digit_map[c1];
		for (int i = 0; i < s1.size(); i++) {
			first_vec.push_back(string(1,s1[i]));
		}
		for (int i = 1; i < digits.size(); i++) {
			vector<string> second_vec;
			char c = digits[i];
			string s = digit_map[c];
			for (int j = 0; j < s.size(); j++) {
				char in_c = s[j];
				for (it_vec = first_vec.begin(); it_vec != first_vec.end(); it_vec++) {
					string first_s = *it_vec;
					second_vec.push_back(first_s + in_c);
				}
			}
			first_vec = second_vec;
		}
		return first_vec;
    }
};

void letterCombinations_test_case1() {
	string s = "2389";
	Solution solution;
	vector<string> r_v = solution.letterCombinations(s);
	cout << r_v.size() << endl;
}

int main_letterCombinations(int argc, char **argv) {
	letterCombinations_test_case1();
	return 0;
}