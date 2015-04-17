#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int m_l=0, m_r=m-1, n_l=0, n_r=n-1;
		int middle_idx1,middle_idx2;
		int middle_num = 1;
		if ((m+n)%2==0) {
			middle_num = 2;
			middle_idx1 = (m+n-1)/2;
			middle_idx2 = (m+n)/2;
		} else {
			middle_num=1;
			middle_idx1 = (m+n)/2;
			middle_idx2 = -1;
		}
		int al = A[m_l], ar = A[m_r], bl = B[n_l], br = B[n_r];
		if (al >= br) {
			
		} else if (bl >= ar) {
			
		}

		return 0;
    }
};

void findMedianSortedArrays_test_case1() {
	Solution solution;
	int A[] = {1,3,7,9};
	int B[] = {2,6,10,12};
	double median = solution.findMedianSortedArrays(A,4,B,4);
	cout << median << endl;
}

int main_findMedianSortedArrays(int argc, char **argv) {
	findMedianSortedArrays_test_case1();
	return 0;
}