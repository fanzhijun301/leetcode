#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
		if (n == 0) return;
        int i=m-1,j=n-1,k=m+n-1;
		while (i>=0 && j>=0) {
			if (A[i] > B[j]) {
				A[k] = A[i];
				i--; k--;
			} else {
				A[k] = B[j];
				j--; k--;
			}
		}
		if (j >= 0) {
			while (j >= 0) {
				A[k] = B[j]; 
				j--; k--;
			}
		}
    }
};

void mergeSortedArray_test_case1() {
	int A[] = {1,3,5,7,9,0,0,0,0};
	int B[] = {2,4,6,8};
	Solution solution;
	solution.merge(A,5,B,4);
	cout << "haha" << endl;
}

int main_mergeSortedArray(int argc, char **argv) {
	mergeSortedArray_test_case1();
	return 0;
}