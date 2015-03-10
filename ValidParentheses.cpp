#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> pa_stack;
		for (int i = 0; i < s.length(); i++) {
			char c = s.at(i);
			if (c == '(' || c == '[' || c == '{') pa_stack.push(c);
			else {
				if (pa_stack.empty()) return false;
				char top_c = pa_stack.top();
				if (c == ')' && top_c != '(') return false;
				if (c == ']' && top_c != '[') return false;
				if (c == '}' && top_c != '{') return false;
				pa_stack.pop();
			}
		}
		if (pa_stack.empty()) return true;
		else return false;
    }
};

void isValid_test_case1() {
	string s = "()[]{}";
	//string s = "([)]";
	//string s = "]";
	Solution solution;
	bool is_valid = solution.isValid(s);
	cout << is_valid << endl;
}

int main_isValid(int argc, char **argv) {
	isValid_test_case1();
	return 0;
}