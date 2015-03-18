#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int largest = 0;
		if (height.size() == 0) return largest;
		vector<pair<int,int>> pos_vec;
		for (int i = 1; i < height.size()-1; i++) {
			if (height[i-1] < height[i] && height[i+1] < height[i]) 
				pos_vec.push_back(pair<int,int>(i,1));
			if (height[i-1] > height[i] && height[i+1] > height[i])
				pos_vec.push_back(pair<int,int>(i,2));
		}
		
		return largest;
    }
};

void largestRectangleArea_test_case1() {
	Solution solution;
	int arr[] = {2,1,5,6,2,3};
	vector<int> height(arr, arr + 6);
	int largest = solution.largestRectangleArea(height);
	cout << largest << endl;
}

int main_largestRectangleArea(int argc, char **argv) {
	largestRectangleArea_test_case1();
	return 0;
}