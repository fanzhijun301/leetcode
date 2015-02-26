#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
		
		while (n > 0) {
			int a = n % 26;
			if (a == 0) a = 26;
			char c = a + 0x40;
			s.insert(0, 1, c);

			if (a == 26) n -=26;
			n = n / 26;
		}
		
		return s;
    }
};

void convertToTitle_test_case1() {
	Solution solution;
	for (int i = 1; i <= 100; i++) {
		string s = solution.convertToTitle(i);
		cout << i<<" " <<s << endl;
	}
}

int _main_convertToTitle(int argc, char **argv) {
	convertToTitle_test_case1();
	return 0;
}