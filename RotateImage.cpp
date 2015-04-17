#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		if (n <=1) return;
		for (int i = 0; i < n/2; i++) {
			for (int j = i; j < n-i-1; j++) {
				//top right
				matrix[i][j] += matrix[j][n-1-i];
				matrix[j][n-1-i] = matrix[i][j] - matrix[j][n-1-i];
				matrix[i][j] -= matrix[j][n-1-i];
				//left top
				matrix[i][j] += matrix[n-1-j][i];
				matrix[n-1-j][i] = matrix[i][j] - matrix[n-1-j][i];
				matrix[i][j] -= matrix[n-1-j][i];
				//bottom left
				matrix[n-1-j][i] += matrix[n-1-i][n-1-j];
				matrix[n-1-i][n-1-j] = matrix[n-1-j][i] - matrix[n-1-i][n-1-j];
				matrix[n-1-j][i] -= matrix[n-1-i][n-1-j];
			}
		}
    }
};

void rotate_test_case1() {
	int arr1[] = {1, 2, 3, 4};
	int arr2[] = {5, 6, 7, 8};
	int arr3[] = {9, 10,11,12};
	int arr4[] = {13,14,15,16};
	vector<int> vec1(arr1,arr1+4);
	vector<int> vec2(arr2,arr2+4);
	vector<int> vec3(arr3,arr3+4);
	vector<int> vec4(arr4,arr4+4);
	vector<vector<int>> matrix;
	matrix.push_back(vec1); matrix.push_back(vec2);
	matrix.push_back(vec3); matrix.push_back(vec4);
	Solution solution;
	solution.rotate(matrix);
	cout << matrix.size() << endl;
}

int main_rotateImage(int argc, char **argv) {
	rotate_test_case1();
	return 0;
}