#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int *arr = new int[n+1];
		if (n <= 1) return 1;
		arr[0] = 1; arr[1] = 1;
		for (int i = 2; i <= n; i++) {
			int sum = 0;
			for (int j = 0; j < i; j++) {
				sum += arr[j] * arr[i-1-j];
			}
			arr[i] = sum;
		}
		return arr[n];
    }
};

void numTrees_test_case1() {
	Solution solution;
	int numtree = solution.numTrees(3);
	cout << numtree << endl;
}

int main_numTrees(int argc, char **argv) {
	numTrees_test_case1();
	return 0;
}