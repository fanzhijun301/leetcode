#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result_v;
		set<string> con_set;
		set<string>::iterator it_set;
		if (n==0) return result_v;
		string first_s = "";
		for (int i = 0; i < n; i++) first_s += "()";
		result_v.push_back(first_s);
		con_set.insert(first_s);
		
		for (int len = 2; len <= n; len++) {
			vector<string> tmp_v;
			for (int result_idx = 0; result_idx < result_v.size(); result_idx++) {
				string res_s = result_v[result_idx];
				string pre_s = res_s.substr(0,2*(len-1));
				
				for (int i = 0; i < pre_s.size(); i++) {
					char c_i = pre_s[i];
					if (c_i == '(') {continue;}
					for (int j = i+1; j <= pre_s.size(); j++) {
						if (j == pre_s.size()) {
							string copy_s = pre_s;
							copy_s.append(1, ')');
							copy_s.insert(i, 1,'(');
							if (res_s.size() > 2*len)copy_s.append(res_s.substr(2*len));
							tmp_v.push_back(copy_s);
						} else {
							char c_j = pre_s[j];
							if (c_j == ')') { continue;}
							string copy_s = pre_s;
							copy_s.insert(j, 1, ')');
							copy_s.insert(i, 1,'(');
							if (res_s.size() > 2*len)copy_s.append(res_s.substr(2*len));
							tmp_v.push_back(copy_s);
						}
					}
				}
			}
			for (vector<string>::iterator it_v = tmp_v.begin(); it_v != tmp_v.end(); it_v++)
			{
				string insert_s = *it_v;
				it_set = con_set.find(insert_s);
				if (it_set == con_set.end()) { 
					result_v.push_back(insert_s);
					con_set.insert(insert_s);
				}
			}
		}
		return result_v;
    }
};

class Solution {
    string onePossible;
    vector<string> allPossible;
public:
    void getans_dfs(string onePossible, int inleft, int inright, int len){
        if(inleft == 0 && inright == 0) allPossible.push_back(onePossible);
        if(inleft >0 && inleft <=len/2) getans_dfs(onePossible+'(', inleft-1, inright,len); 
        if(inright >0 && inright <=len/2 && inleft < inright) getans_dfs(onePossible+')', inleft, inright-1, len);
    }
    vector<string> generateParenthesis(int n){
        getans_dfs(onePossible, n, n, n*2);
        return allPossible;
    }
};

void generateParenthesis_test_case1() {
	Solution solution;
	vector<string> result_v = solution.generateParenthesis(3);
	cout << result_v.size() << endl;
}

int main_generateParenthesis(int argc, char **argv) {
	generateParenthesis_test_case1();
	return 0;
}