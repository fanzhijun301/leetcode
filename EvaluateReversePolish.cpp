#include<vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> cacu_vec;
        vector<string>::iterator it_tokens;
        for (it_tokens = tokens.begin(); it_tokens != tokens.end(); it_tokens++) {
        	string token = *it_tokens;
        	if (token == "+" || token == "-" || token == "*" || token == "/") {
        		int v2 = cacu_vec.back();
        		cacu_vec.pop_back();
        		int v1 = cacu_vec.back();
        		cacu_vec.pop_back();
        		int cacu_value = 0;
        		if (token == "+") cacu_value = v1 + v2;
        		else if (token == "-") cacu_value = v1 - v2;
        		else if (token == "*") cacu_value = v1 * v2;
        		else if (token == "/") cacu_value = v1 / v2;
        		cacu_vec.push_back(cacu_value);
        	} else {
        		int v = atoi(token.c_str());
        		cacu_vec.push_back(v);
        	}
        }
        int result_value = cacu_vec.back();
        cacu_vec.pop_back();
        return result_value;
    }
};

int main(int argc, char **argv) {
	Solution solution;
	vector<string> tokens;
	//tokens.push_back("2"); tokens.push_back("1"); tokens.push_back("+"); tokens.push_back("3"); tokens.push_back("*");
	tokens.push_back("4"); tokens.push_back("13"); tokens.push_back("5"); tokens.push_back("/"); tokens.push_back("+");
	int r = solution.evalRPN(tokens);
	cout << r << endl;
}
