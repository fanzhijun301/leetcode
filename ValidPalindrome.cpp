#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		if (s.length() == 0) return true;
		transform(s.begin(),s.end(),s.begin(), ::tolower);
		int i = 0, j = s.length() - 1;
		while (true) {
			while (!(s.at(i)>='a' && s.at(i)<='z' || s.at(i)>='0' && s.at(i)<='9')){
				i++;
				if (i >= s.length()) break;
			}
			while (!(s.at(j)>='a' && s.at(j)<='z' || s.at(j)>='0' && s.at(j)<='9')) {
				j--;
				if (j < 0) break;
			}
			if (i >= s.length() || j < 0) break;

			if (s.at(i) != s.at(j)) return false;
			i++; j--;
			if (i>=j) break;
		}
		return true;
    }
};

void isPalindrome_test_case1() {
	string s1 = "aba";
	string s2 = "A man, a plan, a canal: Panama";
	string s3 = "race a car";
	string s4 = " ";

	Solution solution;
	bool is_pa = solution.isPalindrome(s2);
	cout << is_pa << endl;
}

int main_isPalindrome(int argc, char **argv) {
	isPalindrome_test_case1();
	return 0;
}