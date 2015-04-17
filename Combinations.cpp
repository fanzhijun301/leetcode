#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result_vv;
		if (k==0 || n==0 || k>n) return result_vv;
		if (k == 1) {
			for (int i=1; i <=n; i++) {
				vector<int> in_vec;
				in_vec.push_back(i);
				result_vv.push_back(in_vec);
			}
			return result_vv;
		}

		vector<int> pos_vec(k,0);
		pos_vec[0] = 0;
		int pos = 0;
		while (true) {
			if (pos < 0) break;
			if (pos == k-1) result_vv.push_back(pos_vec);

			if (pos_vec[pos]>=n-k+pos+1) {
				pos--;
				continue;
			}
			pos_vec[pos]++;
			if (pos < k-1) {			
				pos++;
				while (pos <= k-1) {
					pos_vec[pos] = pos_vec[pos-1]+1;
					pos++;
				}
				pos--;
			} 
		}
		return result_vv;
    }
};

void combine_test_case1() {
	Solution solution;
	vector<vector<int> > result_vv = solution.combine(3,1);
	cout << result_vv.size() << endl;
}

int main_combinations(int argc, char **argv) {
	combine_test_case1();
	return 0;
}
