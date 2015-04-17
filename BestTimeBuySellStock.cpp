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

	int maxProfit_2(vector<int> &prices) {
		if (prices.size() <=1) return 0;
		int valley=-1, profit=0;
		bool last_stat = false;
		int last_price;
		for (int i = 0; i < prices.size(); i++) {
			int price = prices.at(i);
			if (i == 0) {
				valley = price;
				last_price = price;
				continue;
			}
			if (price == last_price) continue;

			if (price < prices[i-1]) {
				if (last_stat) {
					profit += last_price-valley;
				}
			}
			else if (price > prices[i-1]) {
				if (!last_stat) {
					valley = last_price;
				}
			}
			if (price > last_price) last_stat = true;
			else last_stat = false;
			last_price = price;
		}
		if (last_stat) profit += last_price-valley;

		return profit;
    }
};

void maxProfit1_test_case1() {
	int arr[] = {9,8,7,6,5,4,3,2};
	vector<int> prices(arr, arr + sizeof(arr)/sizeof(int));
	Solution solution;
	int mp = solution.maxProfit(prices);
	cout << mp << endl;
}

void maxProfit2_test_case1() {
	//int arr[] = {2,8,3,7,4,6,1};
	//int arr[] = {2,8,3,7,4,6,9};
	//int arr[] = {10,8,3,7,4,6,1};
	//int arr[] = {6,8};
	int arr[] = {5,2,3,2,6,6,2,9,1,0,7,4,5,0};
	vector<int> prices(arr, arr+ sizeof(arr)/sizeof(int));
	Solution solution;
	int mp = solution.maxProfit_2(prices);
	cout << mp << endl;
}

int main(int argc, char **argv) {
	maxProfit2_test_case1();
	return 0;
}
