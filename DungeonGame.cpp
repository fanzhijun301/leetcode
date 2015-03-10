#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
		int m_size = dungeon.size();
		if (m_size == 0) return 1;
		vector<int> in_vec = dungeon.at(0);
		int n_size = in_vec.size();
		if (n_size == 0) return 1;

        vector<vector<pair<int,int> > > min_matrix;
		vector<pair<int,int> > in_pair;
		for (int i = 0; i < m_size; i++) {
			min_matrix.push_back(in_pair);
			vector<pair<int, int> > &tmp_p = min_matrix.back();
			for (int j = 0; j < n_size; j++) {
				tmp_p.push_back(pair<int,int>());
			}
		}

		for (int i = 0; i < m_size; i++) {
			for (int j = 0; j < n_size; j++) {
				int v = dungeon[i][j];
				pair<int,int> &min_leave = min_matrix[i][j];
				if (i == 0 && j == 0) {
					if (v > 0) {min_leave.first = 1; min_leave.second = v + 1;}
					else {min_leave.first = 1-v; min_leave.second = 1;}
				} else {
					pair<int, int> last_leave, tmp_leave;
					if (i == 0) last_leave = min_matrix[0][j-1];
					else if (j == 0) last_leave = min_matrix[i-1][0];
					else {
						last_leave = min_matrix[i][j-1];
						tmp_leave = min_matrix[i-1][j];
						if (tmp_leave.first < last_leave.first) last_leave = tmp_leave;
						else if (tmp_leave.first == last_leave.first 
							&& tmp_leave.second > last_leave.second) last_leave = tmp_leave;
					}
					if (v > 0) {min_leave.first = last_leave.first; min_leave.second = last_leave.second + v;}
					else {
						if (last_leave.second + v >= 1) {
							min_leave.first = last_leave.first; min_leave.second = last_leave.second + v;
						} else {
							min_leave.first = last_leave.first + (1 - last_leave.second - v);
							min_leave.second = 1;
						}
					}
				}	
			}
		}
		pair<int,int> last_leave = min_matrix[m_size-1][n_size-1];
		return last_leave.first;
    }
};

void calculateMinimumHP_test_case1() {
	int len = 3;
	int arr1[] = {-2,-3,3};
	int arr2[] = {-5,-10,1};
	int arr3[] = {10,30,-5};

	vector<int> vec1(arr1, arr1 + len);
	vector<int> vec2(arr2, arr2 + len);
	vector<int> vec3(arr3, arr3 + len);

	vector<vector<int> > dungeon_vec;
	dungeon_vec.push_back(vec1);
	dungeon_vec.push_back(vec2);
	dungeon_vec.push_back(vec3);

	Solution solution;
	int min_v = solution.calculateMinimumHP(dungeon_vec);
	cout << min_v << endl;
}

void calculateMinimumHP_test_case2() {
	int len = 3;
	int arr1[] = {3,-20,30};
	int arr2[] = {-3,4,0};
	
	vector<int> vec1(arr1, arr1 + len);
	vector<int> vec2(arr2, arr2 + len);
	
	vector<vector<int> > dungeon_vec;
	dungeon_vec.push_back(vec1);
	dungeon_vec.push_back(vec2);
	
	Solution solution;
	int min_v = solution.calculateMinimumHP(dungeon_vec);
	cout << min_v << endl;
}

void calculateMinimumHP_test_case3() {
	int len = 3;
	int arr1[] = {1,-3,3};
	int arr2[] = {0,-2,0};
	int arr3[] = {-3,-3,-3};

	vector<int> vec1(arr1, arr1 + len);
	vector<int> vec2(arr2, arr2 + len);
	vector<int> vec3(arr3, arr3 + len);

	vector<vector<int> > dungeon_vec;
	dungeon_vec.push_back(vec1);
	dungeon_vec.push_back(vec2);
	dungeon_vec.push_back(vec3);

	Solution solution;
	int min_v = solution.calculateMinimumHP(dungeon_vec);
	cout << min_v << endl;
}

int main_calculateMinimumHP(int argc, char **argv) {
	calculateMinimumHP_test_case3();
	return 0;
}
