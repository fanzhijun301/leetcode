#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> split_vec;
        split_str(s, " ", split_vec);
        s = "";
        for (int i = split_vec.size() - 1; i >= 0; i--) {
        	if (i == (split_vec.size() - 1)) s = split_vec.at(i);
        	else s += " " + split_vec.at(i);
        }
    }
    
    void split_str(string src_str, string split, vector<string> &split_vec) {
    	size_t last_pos = 0;
		size_t pos = src_str.find(split);
    	while (pos != string::npos) {
    		string sub_str = src_str.substr(last_pos, pos-last_pos);
    		if (sub_str.size() > 0)split_vec.push_back(sub_str);
    		last_pos = pos + split.length();
    		pos = src_str.find(split, last_pos);
    	}
    	string sub_str = src_str.substr(last_pos);
    	if (sub_str.size() > 0)split_vec.push_back(sub_str);
    }
};

int main(int argc,char **argv) {
	Solution solution;
	string s = "        the   sky is blue           ";
	vector<string> split_vec;
	solution.split_str(s, " ", split_vec);
	vector<string>::iterator it;
	for (it = split_vec.begin(); it != split_vec.end(); it++) {
		string sub_str = *it;
		cout << sub_str << endl;
	}
	
	solution.reverseWords(s);
	cout << s << endl;
}
