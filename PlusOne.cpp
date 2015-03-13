#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		if (digits.size() == 0) return digits;
        bool need_plus_one = false;
		for (int i = digits.size()-1; i>=0; i--) {
			if (digits[i] == 9) { digits[i] = 0; need_plus_one = true;}
			else {digits[i]++; need_plus_one = false; break;}
		}
		if (need_plus_one) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
    }
};

void plusOne_test_case1() {
	int arr[] = {9,9,9,9,9};
	vector<int> digits(arr, arr + sizeof(arr)/sizeof(int));
	Solution solution;
	vector<int> r_vec = solution.plusOne(digits);
	cout << r_vec.size() << endl;
}

int main_plus_one(int argc, char **argv) {
	plusOne_test_case1();
	return 0;
}