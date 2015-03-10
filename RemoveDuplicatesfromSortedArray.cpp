#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates_1(int A[], int n) {
		if (n == 0) return 0;
        int p1=1,p2=1;
		while (p2 < n) {
			if (A[p1-1] == A[p2]) p2++;
			else {A[p1] = A[p2]; p1++; p2++;}
		}
		return p1;
    }
	int removeDuplicates(int A[], int n) {
		if (n <=2) return n;
        int p1=2,p2=2;
		while (p2 < n) {
			if (A[p1-1] == A[p2] && A[p1-2] == A[p2]) p2++;
			else {A[p1] = A[p2]; p1++; p2++;}
		}
		return p1;
    }
};

void removeDuplicates_test_case1() {
	int arr[] = {1,1,2,3,3,3,4,4,4,4,4,4};
	Solution solution;
	int len = solution.removeDuplicates(arr, sizeof(arr)/sizeof(int));
	cout << len << endl;
}

int main_removeDuplicates(int argc,char **argv) {
	removeDuplicates_test_case1();
	return 0;
}