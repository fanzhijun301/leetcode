#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
		if (m <= 1 && n <= 1) return 1;

        int *arr = new int[m * n];
		for (int i = 0; i < n; i++) *(arr + i) = 1;
		for (int i = 0; i < m; i++) *(arr + i * n) = 1;
		
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				*(arr + i * n + j) = *(arr + i * n + j-1) + *(arr + (i-1)*n + j);
			}
		}
		return *(arr + (m-1) * n + n-1);
    }
};

void uniquePaths_test_case1() {
	Solution solution;
	int up = solution.uniquePaths(3,7);
	cout << up << endl;
}

int main_uniquePaths(int argc, char **argv) {
	uniquePaths_test_case1();
	return 0;
}
