#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (obstacleGrid.size() == 0) return 0;
		else if (obstacleGrid.size() ==1) {
			vector<int> in_vec = obstacleGrid.at(0);
			if (in_vec.size() == 1) {
				if (in_vec.at(0) == 1) return 0;
				else return 1;
			}
		} 
		vector<int> last_vec = obstacleGrid.at(obstacleGrid.size()-1);
		int last_value = last_vec.at(last_vec.size()-1);
		if (last_value == 1) return 0;
		
		for (int i = 0; i < obstacleGrid.size(); i++) {
			vector<int> &in_vec = obstacleGrid.at(i);
			for (int j = 0; j < in_vec.size(); j++) {
				if (in_vec.at(j) == 1) in_vec.at(j) = -1;
			}
		}

		vector<int> &in_vec = obstacleGrid.at(0);
		for (int i = 0; i < in_vec.size(); i++) {
			if (in_vec.at(i) == -1) break;
			else in_vec.at(i) = 1;
		}
		for (int i = 0; i < obstacleGrid.size(); i++) {
			vector<int> &in_vec = obstacleGrid.at(i);
			if (in_vec.at(0) == -1) break;
			else in_vec.at(0) = 1;
		}

		for (int i = 1; i < obstacleGrid.size(); i++) {
			vector<int> up_vec = obstacleGrid.at(i-1);
			vector<int> &in_vec = obstacleGrid.at(i);
			for (int j = 1; j < in_vec.size(); j++) {
				int value = in_vec.at(j);
				if (value == -1) continue;
				int left_value = 0, up_value = 0;
				if (in_vec.at(j-1) != -1) left_value = in_vec.at(j-1);
				if (up_vec.at(j) != -1) up_value = up_vec.at(j);
				in_vec.at(j) = left_value + up_value;
			}
		}
		last_vec = obstacleGrid.at(obstacleGrid.size()-1);
		last_value = last_vec.at(last_vec.size()-1);
		return last_value;
    }
};

void uniquePathsWithObstacles_test_case1() {
	int arr1[] = {0,1,0};
	int arr2[] = {0,0,0};
	int arr3[] = {0,1,0};
	vector<vector<int> > obstacleGrid;
	vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(int));
	vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(int));
	vector<int> vec3(arr3, arr3 + sizeof(arr3)/sizeof(int));

	obstacleGrid.push_back(vec1); obstacleGrid.push_back(vec2);
	obstacleGrid.push_back(vec3);
	
	Solution solution;
	int unique_value = solution.uniquePathsWithObstacles(obstacleGrid);
	cout << unique_value << endl;
}

int main(int argc, char **argv) {
	uniquePathsWithObstacles_test_case1();
	return 0;
}
