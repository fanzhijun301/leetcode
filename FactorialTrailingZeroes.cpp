#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int zeros = 0;
		while (n >=5) {
			zeros += n / 5;
			n /= 5;
		}
		return zeros;
    }
};

void trailingZeroes_test_case1() {
	Solution solution;

	int zeros = solution.trailingZeroes(30);
	cout << zeros << endl;
}

int main_trailingZeroes(int argc, char **argv) {
	trailingZeroes_test_case1();
	return 0;
}