#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> r_v;
		if (matrix.size() == 0 || matrix[0].size() == 0) return r_v;

		int left = -1,right=matrix[0].size(),top=-1,down=matrix.size();
		int order = 1;
		bool over_loop = false;
		while (true) {
			if (over_loop) break;
			switch (order) {
				case 1:
					if (left + 1 >= right) {over_loop = true; break;}
					for (int i = left + 1; i <right; i++) r_v.push_back(matrix[top+1][i]);
					top += 1; order = 2;
					break;
				case 2:
					if (top + 1 >= down) {over_loop = true; break;}
					for (int i = top + 1; i < down; i++) r_v.push_back(matrix[i][right-1]);
					right -= 1; order = 3;
					break;
				case 3:
					if (right-1<=left) {over_loop = true; break;}
					for (int i = right-1; i > left; i--) r_v.push_back(matrix[down-1][i]);
					down -= 1; order = 4;
					break;
				case 4:
					if (down-1<=top) {over_loop = true; break;}
					for (int i = down-1; i > top; i--) r_v.push_back(matrix[i][left+1]);
					left += 1; order = 1;
					break;
			}
		}
		return r_v;
    }
};

void spiralOrder_test_case1() {
	
	int arr1[] = {1,2,3};
	int arr2[] = {4,5,6};
	int arr3[] = {7,8,9};
	vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(int));
	vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(int));
	vector<int> vec3(arr3, arr3 + sizeof(arr3)/sizeof(int));

	vector<vector<int> > matrix;
	matrix.push_back(vec1); matrix.push_back(vec2); matrix.push_back(vec3);
	Solution solution;
	vector<int> r_v = solution.spiralOrder(matrix);
	cout << r_v.size() << endl;
}

int main_spiralMatrix(int argc, char **argv) {
	spiralOrder_test_case1();
	return 0;
}