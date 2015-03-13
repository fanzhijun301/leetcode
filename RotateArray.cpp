#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
		if (k > n) k = k % n;
		if (k == 0) return;
        vector<int> cache_vec;
		vector<int>::iterator it_vec;
		for (int i = n-k; i < n; i++) cache_vec.push_back(nums[i]);
		for (int i = n-k-1; i >= 0; i--) nums[i + k] = nums[i];
		for (int i = 0; i < cache_vec.size(); i++) {
			nums[i] = cache_vec[i];
		}
    }
};

void rotateArray_test_case1() {
	int arr[] = {1,2,3,4,5,6,7};
	Solution solution;
	solution.rotate(arr, 7, 3);
	for (int i = 0; i < 7; i++) printf("%d ", arr[i]);
	printf("\n");
}

int main_rotate_array(int argc, char **argv) {
	rotateArray_test_case1();
	return 0;
}