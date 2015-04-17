#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
		if (s == NULL) return 0;
        const char *p1 = NULL,*p2=s;
		bool first = false;
		while (*p2 != '\0') {
			if (*p2 != ' ') {
				if (!first) {first = true; p1 = p2;}
			} else first = false;
			p2++;
		}
		p2--;
		while (*p2==' ')p2--;
		if (p1 == NULL) return 0;
		else return p2-p1+1;
    }
};

void lengthOfLastWord_test_case1() {
	const char *arr = "  Hello   World"; 
	Solution solution;
	int len = solution.lengthOfLastWord(arr);
	cout << len << endl;
}

int main_lengthOfLastWord(int argc, char **argv) {
	lengthOfLastWord_test_case1();
	return 0;
}