#include <vector>
#include <iostream>
#include <map>;

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result_vec;
        if(num.size() < 3) return result_vec;

        map<int,int> stat_map;
		map<int,int>::iterator it_map;
		vector<int>::iterator it_vec;
		for (it_vec = num.begin(); it_vec != num.end(); it_vec++) {
			int n = *it_vec;
			it_map = stat_map.find(n);
			if (it_map == stat_map.end()) {
				stat_map.insert(pair<int,int>(n,0));
				it_map = stat_map.find(n);
			}
			int stat = it_map->second;
			stat_map[n] = stat+1;
		}
		//
		vector<pair<int,int>> stat_vec;
		int zero_pos = -1, minus_pos = -1;
		for (it_map = stat_map.begin(); it_map != stat_map.end(); it_map++) {
			pair<int,int> in_pair(it_map->first,it_map->second);
			stat_vec.push_back(in_pair);
			minus_pos++;
			if (it_map->first <= 0) zero_pos = minus_pos;
		}
		if (zero_pos == -1) return result_vec; //all numbers are positive
		
		//first step: find all possible two negative numbers
		
		//second step: find all possible two positive numbers

		//third step contain zeros

    }
};

void threeSum_test_case1() {
	
}

int main(int argc, char **argv) {
	threeSum_test_case1();
	return 0;
}