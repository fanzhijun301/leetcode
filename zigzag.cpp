#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
		if (nRows == 1) return s;
        vector<string> str_vec(nRows, "");
		int direct = 0;
		int curr_index = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s.at(i);
			string &curr_s = str_vec.at(curr_index);
			curr_s.push_back(c);
			if (direct == 0) {
				curr_index += 1;
				if (curr_index >= nRows) {
					curr_index = nRows - 2;
					direct = 1;
				}
			} else if (direct == 1) {
				curr_index -= 1;
				if (curr_index < 0) {
					curr_index = 1;
					direct = 0;
				}
			}
		}
		string r = "";
		for (int i = 0; i < str_vec.size(); i++) {
			string vs = str_vec.at(i);
			r += vs;
		}
		return r;
    }
};

int main(int argc, char **argv) {
	Solution solution;
	string s = "PA";
	string r = solution.convert(s, 5);
	cout << r << endl;
}
