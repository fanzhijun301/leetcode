#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
		if (len1 == 0) {if (s2 == s3) return true; else return false;} 
		if (len2 == 0) {if (s1 == s3) return true; else return false;}
		if (len3 == 0) {if (len1==0 && len2==0) return true; else return false;}

		vector<vector<pair<int,int>>> pos_vec;
		pos_vec.resize(len3);

		int pos1 = -1,  po2 = -1;
		for (int i = 0; i < len3; i++) {
			char c3 = s3.at(i);
			set<pair<int,int>> pos_set;
			if (i == 0) {
				if (s1.at(0) == c3) pos_set.insert(pair<int,int>(0,-1));
				if (s2.at(0) == c3) pos_set.insert(pair<int,int>(-1,0));
			} else {
				vector<pair<int,int>> &last_vec = pos_vec.at(i-1);
				vector<pair<int,int>>::iterator it_vec;
				for (it_vec = last_vec.begin(); it_vec != last_vec.end(); it_vec++) {
					pair<int,int> in_pair = *it_vec;
					if (in_pair.first + 1 < len1 && s1.at(in_pair.first+1) == c3) 
						pos_set.insert(pair<int,int>(in_pair.first + 1, in_pair.second));
					if (in_pair.second + 1 < len2 && s2.at(in_pair.second+1) == c3) 
						pos_set.insert(pair<int,int>(in_pair.first, in_pair.second + 1));
				}
			}
			if (pos_set.size() == 0) return false;
			vector<pair<int,int>> in_vec;
			set<pair<int,int>>::iterator it_set;
			for (it_set = pos_set.begin(); it_set != pos_set.end(); it_set++) {
				pair<int,int> in_pair = *it_set;
				in_vec.push_back(pair<int,int>(in_pair.first,in_pair.second));
			}
			pos_vec[i] = in_vec;
		}
		vector<pair<int,int>> &last_vec = pos_vec.at(len3-1);
		vector<pair<int,int>>::iterator it_vec;
		for (it_vec = last_vec.begin(); it_vec != last_vec.end(); it_vec++) {
			pair<int,int> in_pair = *it_vec;
			if (in_pair.first == len1-1 && in_pair.second == len2-1) return true;
		}
		return false;
    }
};

void isInterleave_test_case1() {
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	string s32 = "aadbbbaccc";
	Solution solution;
	bool is_inter = solution.isInterleave(s1,s2,s3);
	cout << is_inter << endl;
}

void isInterleave_test_case2() {
	string s1 = "aa";
	string s2 = "ab";
	string s3 = "aaba";
	Solution solution;
	bool is_inter = solution.isInterleave(s1,s2,s3);
	cout << is_inter << endl;
}

void isInterleave_test_case3() {
	string s1 = "a";
	string s2 = "b";
	string s3 = "a";
	Solution solution;
	bool is_inter = solution.isInterleave(s1,s2,s3);
	cout << is_inter << endl;
}

int main_interleavingString(int argc, char **argv) {
	isInterleave_test_case1();
	isInterleave_test_case2();
	isInterleave_test_case3();
	return 0;
}