#include <iostream>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0) return 0;
		char c = s.at(0);
		if (c == '0') return 0;
		
		int *arr = new int[s.size() + 1];
		for (int i = 0; i < s.size() + 1; i++) arr[i] = 0;
		arr[0] = 1; arr[1] = 1;
		
		for (int i = 2; i <= s.size(); i++) {
			int i1 = s.at(i-2) - '0';
			int i2 = s.at(i-1) - '0';

			int num = i1 * 10 + i2;
			
			if (num >= 10 && num <= 26) arr[i] += arr[i - 2];
			if (i2 != 0) arr[i] += arr[i - 1];
		}
		return arr[s.size()];
	}
};