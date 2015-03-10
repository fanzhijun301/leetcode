#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if (prices.size() <= 1) return 0;
		int min_left = INT_MAX;
		int max_profit = INT_MIN;
		for (int i = 0; i < prices.size(); i++) {
			int price = prices.at(i);
			if (i == 0) {min_left = price; continue;}
			int profit = price - min_left;
			if (profit > max_profit) max_profit = profit;
			if (price < min_left) min_left = price;
		}
		if (max_profit < 0) max_profit = 0;
		return max_profit;
    }
};

void maxProfit1_test_case1() {
	int arr[] = {9,8,7,6,5,4,3,2};
	vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));
	Solution solution;
	int mp = solution.maxProfit(prices);
	cout << mp << endl;
}

int main_maxProfit1(int argc, char **argv) {
	maxProfit1_test_case1();
	return 0;
}
