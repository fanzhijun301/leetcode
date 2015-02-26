#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
		if (num.size() < 2) return 0;
		int max_i = 0;
		for (int i = 0; i < num.size(); i++) {
			int n = num.at(i);
			if (n > max_i) max_i = n;
		}
		//int buf_len = 1 << 29;

		int buf_len = max_i / 8 + 1;
        char *buff = (char *)malloc(buf_len * sizeof(char));
		memset(buff, 0, buf_len);
		
		for (int i = 0; i < num.size(); i++) {
			int n = num.at(i);
			int pos_byte = n / 8;
			int pos_bit = n % 8;

			int p = 1 << (7 - pos_bit);
			char *c = buff + pos_byte;
			*c = *c | p;
		}
		
		int max_gap = 0, right_one = -1;
		for (int i = 0; i <= (max_i / 8); i++) {
			char c = buff[i];
			if (c == 0)continue;
			vector<int> pos_vec;
			find_pos(c, pos_vec);
			int begin_pos = i * 8;
			vector<int>::iterator it_vec;
			for (it_vec = pos_vec.begin(); it_vec != pos_vec.end(); it_vec++) {
				int re_pos = *it_vec;
				int curr_pos = begin_pos + re_pos;
				if (right_one == -1) {
					right_one = curr_pos;
					continue;
				} 
				int curr_gap = curr_pos - right_one - 1;
				right_one = curr_pos;
				if (curr_gap > max_gap) max_gap = curr_gap;
			}
		}
		free(buff);

		return max_gap;
    }

	void find_pos(char t, vector<int> &pos_vec) {
		
		for (int j= 0; j < 8; j++) {
			int k = 1 << 7-j;
			if ((t & k) == 0) continue;
			pos_vec.push_back(j);
		}
	}
};

void maximumGap_test_case1() {
	int arr[] = {2,5,8,25,30,10030,INT_MAX};
	vector<int> num_vec(arr, arr + 7);
	Solution solution;
	int max_gap = solution.maximumGap(num_vec);
	cout << max_gap << endl;
	int tmp = INT_MAX - 10030 - 1;
	cout << tmp << endl;
	
}

void maximumGap_test_case2() {
	int arr[] = {1,10000000};
	vector<int> num_vec(arr, arr + 2);
	Solution solution;
	int max_gap = solution.maximumGap(num_vec);
	cout << max_gap << endl;
	int tmp = 10000000 - 1 - 1;
	cout << tmp << endl;
	
}

int main_maximumGap(int argc, char **argv) {
	maximumGap_test_case1();
	
	return 0;
}