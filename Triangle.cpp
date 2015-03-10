#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.size() == 0) return 0;
		int tri_size = triangle.size();
		for (int i = tri_size - 2; i >= 0; i--) {
			vector<int> &vec_up = triangle.at(i);
			vector<int> vec_low = triangle.at(i+1);
			for (int j = 0; j < vec_up.size(); j++) {
				int min_low = (vec_low.at(j) < vec_low.at(j+1))?vec_low.at(j):vec_low.at(j+1);
				vec_up.at(j) += min_low;
			}
		}
		return triangle[0][0];
    }
};

void triangle_test_case1() {
	int arr1[] = {2};
	int arr2[] = {3,4};
	int arr3[] = {6,5,7};
	int arr4[] = {4,1,8,3};
	vector<int> vec1(arr1, arr1 + 1);
	vector<int> vec2(arr2, arr2 + 2);
	vector<int> vec3(arr3, arr3 + 3);
	vector<int> vec4(arr4, arr4 + 4);
	vector<vector<int> > triangle_vec;
	triangle_vec.push_back(vec1);
	triangle_vec.push_back(vec2);
	triangle_vec.push_back(vec3);
	triangle_vec.push_back(vec4);
	
	Solution solution;
	int r = solution.minimumTotal(triangle_vec);
	cout << r << endl;
}

int main_triangle(int argc, char **argv) {
	triangle_test_case1();
	return 0;
}