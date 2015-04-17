#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
		int num_size = num.size();
		if (num_size == 0) return 0;

		vector<vector<int>> stat_vv;
		stat_vv.resize(num_size);
		for (int i = 0; i < num_size; i++) 
		{
			vector<int> in_v(4, 0);
			stat_vv[i] = in_v;
		}
		for (int i = 0; i < num_size; i++) {
			vector<int> &in_v = stat_vv[i];
			if (i <= 1) {
				in_v[0] = num[i];
				in_v[1] = -1;
			} else {
				vector<int> pre_v = stat_vv[i-2];
				in_v[0] = pre_v[2] + num[i];
				in_v[1] = pre_v[3];
			}
			int max_i = INT_MIN;
			int max_p = i;
			for (int j = i; j >=i-2; j--) {
				if (stat_vv[j][0] > max_i) {
					max_i = stat_vv[j][0];
					max_p = j;
				}
				if (j == 0) break;
			}
			in_v[2] = max_i;
			in_v[3] = max_p;
		}
		return stat_vv[num_size-1][2];
    }
};

void houseRobber_test_case1() {
	Solution solution;
	int arr[] = {3,2,7,9,6,4};
	vector<int> num(arr, arr + sizeof(arr)/sizeof(int));
	int rob = solution.rob(num);
	cout << rob << endl;
}

int main_houseRobber(int argc, char **argv) {
	houseRobber_test_case1();
	return 0;
}