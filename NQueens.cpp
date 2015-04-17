#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) { //totalNQueens
        vector<vector<string>> solve_vec_vec;
		if (n==0) return solve_vec_vec;

		vector<int> stat_vec(n,0);
		//init
		for (int i = 0; i < n; i++) stat_vec[i] = 1;
		if (n==1) {
			vector<string> in_vec(1,"Q");
			solve_vec_vec.push_back(in_vec);
			return solve_vec_vec;
		}
		int row = 1;
		
		while (true) {
			//this col is ok?
			if (row == 0 || row > n) break;
			if (stat_vec[row-1] > n) {
				stat_vec[row-1] = 1;
				row--;
				if (row == 0) break;
				stat_vec[row-1]++;
				continue;
			}
			bool isconflict = is_conflict(stat_vec, row);
			if (!isconflict && row == n) 
				solve_vec_vec.push_back(generate_vec(stat_vec, n));
			if (isconflict) {
				if (stat_vec[row-1] < n) stat_vec[row-1] += 1;
				else {
					stat_vec[row-1] = 1; 
					row--;
					if (row == 0) break;
					stat_vec[row-1]++;
				}
			} else {
				if (row < n) {row++; stat_vec[row-1] = 1;}
				else {
					stat_vec[row-1] = 1;
					row--;
					stat_vec[row-1]++;
				}
			}
		}
		
		return solve_vec_vec;
    }

	bool is_conflict(vector<int> &stat_vec, int row) {
		int col_value = stat_vec[row-1];
		int i = row-1, left_v = col_value-1, right_v = col_value + 1; 
		for (int i = row-1; i>=1; i--) {
			if (stat_vec[i-1] == col_value) return true;
			if (stat_vec[i-1] == left_v) return true;
			if (stat_vec[i-1] == right_v) return true;
			left_v--; right_v++;
		}
		return false;
	}

	vector<string> generate_vec(vector<int> &stat_vec,int n) {
		vector<string> queen_vec;
		vector<int>::iterator it_vec;
		for (it_vec = stat_vec.begin(); it_vec != stat_vec.end(); it_vec++) {
			int pos = *it_vec;
			string s(n,'.');
			s[pos-1] = 'Q';
			queen_vec.push_back(s);
		}
		return queen_vec;
	}
};

void solveNQueens_test_case1() {
	Solution solution;

	vector<vector<string> > r_result = solution.solveNQueens(8);
	cout << r_result.size() << endl;
}

int main_solveNQueens(int argc, char **argv) {
	solveNQueens_test_case1();
	return 0;
}