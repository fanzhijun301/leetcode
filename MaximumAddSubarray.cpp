#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
		if (n == 0) return 0;
        vector<int> merge_vec = mergePosNeg(A, n);
		if (merge_vec.size() == 1) {
			if (merge_vec.at(0) > 0) return merge_vec.at(0);
			else {
				int max = INT_MIN;
				for (int i = 0; i < n; i++) {
					int a = A[i];
					if (a > max) max = a;
				}
				return max;
			}
		}

		int max = maxArray(merge_vec);
		return max;
    }

	int maxArray(vector<int> &merge_vec) {
		int max = INT_MIN;
		int curr_add = 0;
		for (int i = 0; i < merge_vec.size(); i++) {
			int v = merge_vec.at(i);
			
		}
		return 0;
	}

	vector<int> mergePosNeg(int A[], int n) {
		vector<int> pos_neg_vec;
		int add = 0;
		bool pos_neg = true; //pos > 0; neg <=0 
		for (int i = 0; i < n; i++) {
			int a = A[i];
			if (i == 0) {
				add = a;
				if (a > 0) pos_neg = true;
				else pos_neg = false;
				continue;
			}
			if (a > 0) {
				if (pos_neg) add += a;
				else {
					pos_neg_vec.push_back(add);
					add = a;
					pos_neg = true;
				}
			} else {
				if (!pos_neg) add += a;
				else {
					pos_neg_vec.push_back(add);
					add = a;
					pos_neg = false;
				}
			}
		}
		pos_neg_vec.push_back(add);

		return pos_neg_vec;
	}
};

void maxSubArray_test_case1() {
	
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	Solution solution;
	int max = solution.maxSubArray(A, sizeof(A)/sizeof(int));
	cout << max << endl;
}

int main_maximumAddSubarray(int argc, char **argv) {
	maxSubArray_test_case1();
	return 0;
}