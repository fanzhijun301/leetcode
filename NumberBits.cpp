#include <iostream>

typedef size_t uint32_t;

using namespace std;

class Solution {
public:
    int hammingWeight(size_t n) {
		int count = 0;
		for (int i = 0; i < 32; i++) {
			count += n & 1;
			n = n >> 1;
		}
		return count;
    }

	uint32_t reverseBits(uint32_t n) {
		size_t pos1 = 1 << 31, pos2 = 1;
		for (int i = 1; i <= 16; i++) {
			size_t v1 = n & pos1;
			size_t v2 = n & pos2;
			if (v1 == 0 && v2 != 0) {
				n = n | pos1; n = n & ~pos2;
			} else if (v1 != 0 && v2 == 0) {
				n = n & ~pos1; n = n | pos2;
			}
			pos1 = pos1 >> 1; pos2 = pos2 << 1;
		}
		return n;
    }
};

int main_numberBits(int argc, char **argv) {
	Solution solution;
	int bit = solution.hammingWeight(11);
	cout << bit << endl;
	size_t rev = solution.reverseBits(1);
	cout << rev << endl;
	return 0;
}