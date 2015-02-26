#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
		if (num.size() == 1) return 0;

        int begin_pos = 0, end_pos = num.size() -1;
		int middle_pos = (begin_pos + end_pos)/2;
		
		while (begin_pos < end_pos) {
			if (is_peak(num, begin_pos)) return begin_pos;
			if (is_peak(num, end_pos)) return end_pos;
			if (is_peak(num, middle_pos)) return middle_pos;
			
			if (num.at(middle_pos) > num.at(middle_pos-1)) {
				begin_pos = middle_pos + 1;
				middle_pos = (begin_pos + end_pos) / 2;
			} else if (num.at(middle_pos) < num.at(middle_pos - 1)) {
				end_pos = middle_pos - 1;
				middle_pos = (begin_pos + end_pos) / 2;
			}
		}
    }

	bool is_peak(const vector<int> &num, int pos) {
		if (pos == 0) { if (num.at(pos) > num.at(pos + 1)) return true;}
		else if (pos == num.size() - 1) {if (num.at(pos) > num.at(pos - 1)) return true;}
		else if (num.at(pos) > num.at(pos-1) && 
				num.at(pos) > num.at(pos+1)) return true;
		return false;
	}
};

void findPeakElement_test_case1() {
	int arr[] = {5,6,4,8,7,5,7,5};
	vector<int> num_vec(arr, arr + 8);
	Solution solution;
	int peak_pos = solution.findPeakElement(num_vec);
	cout << peak_pos << endl;
}

int main_findPeakElement(int argc, char **argv) {
	findPeakElement_test_case1();
	return 0;
}