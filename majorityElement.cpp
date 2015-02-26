#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
		int half_index = num.size() / 2;
        std::priority_queue<int> pq(num.begin(), num.end());
		int i = 0;
		while (!pq.empty()) {
			i++;
			if (i >= half_index) break;
			pq.pop();
		}
		return pq.top();
    }
};

void majorityElement_test_case1() {
	int arr[] = {10,5,6,8,12,9,4,28,6};
	vector<int> num(arr, arr + 4);
	Solution solution;
	cout << solution.majorityElement(num) << endl;
	
}

int _main_majorityElement(int argc, char **argv) {
	majorityElement_test_case1();
	return 0;
}