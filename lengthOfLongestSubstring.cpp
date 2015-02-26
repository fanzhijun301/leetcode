#include<map>
#include<string>
#include<limits.h>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int min_dis = INT_MAX;
        map<char, vector<int>> pos_map;
        map<char, vector<int>>::iterator it_map;
        for (int i = 0; i < s.length(); i++) {
        	char c = s.at(i);
        	
        	it_map = pos_map.find(c);
        	if (it_map == pos_map.end()) {
        		vector<int> pos_vec(2,INT_MIN);
        		pos_map.insert(pair<char, vector<int>>(c, pos_vec));
        		it_map = pos_map.find(c);
        	}
        	vector<int> &pos_vec = it_map->second;
        	int fir_pos = pos_vec.at(0);
        	if (fir_pos == INT_MAX) {
        		pos_vec.at(0) = i;
        	} else {
        		int dis = i - fir_pos;
        		int sec_pos = pos_vec.at(1);
        		if (dis < sec_pos) pos_vec.at(1) = dis;
        		if (dis < min_dis) min_dis = dis;
        		pos_vec.at(0) = i;
        	}
        	cout << c << " " << pos_vec.at(0) << " " << pos_vec.at(1) << endl;
        }
        if (min_dis == INT_MAX) min_dis = s.length();
        return min_dis;
    }
};

int main(int argc, char **argv) {
	string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	Solution solution;
	int min_dis = solution.lengthOfLongestSubstring(s);
	cout << min_dis << endl;
}

