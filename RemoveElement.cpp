#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i=-1,j=0;
		while (j<n) {
			if (A[j++] == elem) {i=j-1; break;}
		}
		while (j<n) {
			if (A[j] == elem) j++;
			else { A[i++] = A[j++];}
		}
		if (i==-1) return n;
		else return i;
    }
};

void removeElement_test_case1() {
	Solution solution;
	int A[] = {1,8,7,2,5,2,6};
	int len = solution.removeElement(A, 7, 2);
	cout << len << endl;
}

int main_removeElement(int argc, char **argv) {
	removeElement_test_case1();
	return 0;
}