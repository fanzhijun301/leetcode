#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0) return 0;
		if (target <= A[0]) return 0;
		if (target > A[n-1]) return n;
		int first = 0, last=n-1, middle = (first + last) / 2;
		while (first < last) {
			int mid_v = A[middle];
			if (target == mid_v) return middle;
			else if (target < mid_v) last = middle-1;
			else first = middle + 1;
			middle = (first + last) / 2;
		}
		int mid_v = A[middle];
		if (target <= mid_v) return middle;
		else return middle + 1;
    }
};

void searchInsert_test_case1() {
	//int arr[] = {1,3,5,6};
	//int arr[] = {1,4,6,7,8,9};
	int arr[] = {1,2,4,6,7};
	Solution solution;
	int pos = solution.searchInsert(arr, 5, 3);
	cout << pos << endl;
}

int main_searchInsertPosition(int argc, char **argv) {
	searchInsert_test_case1();
	return 0;
}