#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
		if (n <= 1) return true;
		
		int can_pos = n-1;
		for (int i = n-2; i >=0; i--) {
			if (can_pos <= i + A[i]) can_pos = i;
		}
		return can_pos == 0 ? true:false;
    }

	int jump(int A[], int n) {
        if (n <=1) return 1;
		vector<pair<int,int> > min_step_vec;
		vector<pair<int,int> >::iterator it_vec;
		int can_pos = n-1;
		for (int i = n-2; i >=0; i--) {
			int a = A[i];
			if (can_pos <= i + a) can_pos = i;
			else continue;
			
			if (i + a >= n-1){
				it_vec = min_step_vec.begin();
				min_step_vec.insert(it_vec, pair<int,int>(i,1)); 
				continue;
			} 
			int min_v = INT_MAX;
			it_vec = min_step_vec.begin();
			for (; it_vec != min_step_vec.end(); it_vec++) {
				pair<int,int> pos_min = *it_vec;
				if (pos_min.first > i + a) break;
				else if (pos_min.second < min_v) min_v = pos_min.second;
			}
			if (min_v != INT_MAX) {
				it_vec = min_step_vec.begin();
				min_step_vec.insert(it_vec, pair<int,int>(i,min_v+1));
			}
		}
		return min_step_vec[0].second;
    }
};

void canJump_test_case1() {

	//int A[] = {2,3,1,1,4};
	int A[] = {3,2,1,0,4};

	Solution solution;
	bool can = solution.canJump(A, 5);
	cout << can << endl;
}

void canJump_test_case2() {
	//int A[] = {2,3,1,1,4};
	int A[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

	Solution solution;
	int min_step = solution.jump(A, sizeof(A)/sizeof(int));
	cout << min_step << endl;
}

int main_jumGame(int argc, char **argv) {
	canJump_test_case2();
	return 0;
}