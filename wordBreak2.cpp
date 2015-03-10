#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, set<string> &dict) {
		set<string>::iterator it_set;
		vector<vector<int> > pos_vec_vec;
		vector<vector<int> >::iterator it_vec_vec;
		vector<int> pos_vec; pos_vec.push_back(0);
		vector<int>::iterator it_vec;
		for (int i = 0; i <= s.length(); i++) {
			vector<int> in_vec;
			bool have_pushed = false;
			for (it_vec = pos_vec.begin(); it_vec != pos_vec.end(); it_vec++) {
				int pre_pos = *it_vec;
				string subs = s.substr(pre_pos, i-pre_pos);
				it_set = dict.find(subs);
				if (it_set != dict.end()) {
					have_pushed = true;
					in_vec.push_back(pre_pos);
				}
			}
			if (have_pushed) pos_vec.push_back(i);
			pos_vec_vec.push_back(in_vec);
		}
		
        vector<string> break_vec;
		list<string> in_list;
		find_break(pos_vec_vec, pos_vec_vec.size() - 1, s, in_list, break_vec);
		
		return break_vec;
    }

	void find_break(vector<vector<int> > &pos_vec_vec, int pos, string s, list<string> &in_list
		, vector<string> &break_vec) {
		vector<int> in_vec = pos_vec_vec.at(pos);
		for (int i = 0; i < in_vec.size(); i++) {
			int pre_pos = in_vec.at(i);
			string pre_s = s.substr(pre_pos, pos-pre_pos);
			list<string>::iterator it_list = in_list.begin();
			in_list.insert(it_list, pre_s);
			find_break(pos_vec_vec, pre_pos, s, in_list, break_vec);
			if (pre_pos == 0) {
				//output
				bool first = true;
				string tmp_s = "";
				for (it_list = in_list.begin(); it_list != in_list.end(); it_list++) {
					if (first) {
						tmp_s = *it_list;
						first = false;
					} else {tmp_s += " " + *it_list;}
				}
				break_vec.push_back(tmp_s);
			}
			it_list = in_list.begin();
			in_list.erase(it_list);
		}
	}
};

void wordBreak2_test_case1() {
	string s = "catsanddog";
	string arr[] = {"cat", "cats", "and", "sand", "dog", "andd", "sandd", "og"};
	set<string> dict(arr, arr + 8);
	Solution solution;
	vector<string> break_result = solution.wordBreak(s, dict);
	vector<string>::iterator it_vec;
	for (it_vec = break_result.begin(); it_vec != break_result.end(); it_vec++) {
		cout << *it_vec << endl;
	}
}

int main_wordBreak2(int argc, char **argv) {
	wordBreak2_test_case1();
	return 0;
}
