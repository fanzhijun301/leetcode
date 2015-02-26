#include<vector>
#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> num_index_map;
        map<int, int>::iterator it_map;
        for (int i = 0; i < numbers.size(); i++) {
        	int n = numbers.at(i);
        	num_index_map[n] = i + 1;
        }
        vector<int> result_vec;
        for (int i = 0; i < numbers.size(); i++) {
        	int n = numbers.at(i);
        	int leave = target - n;
        	it_map = num_index_map.find(leave);
        	if (it_map != num_index_map.end()) {
        		int leave_index = it_map->second;
        		if (i+1 == leave_index) continue;
        		result_vec.push_back(i+1);
        		result_vec.push_back(leave_index);
        		break;
        	}
        }
        return result_vec;
    }
};


int main(int argc, char **argv) {
	Solution solution;
	int myints[] ={0, 4, 3, 0};
	vector<int> numbers(myints, myints + sizeof(myints) / sizeof(int));
	vector<int> result = solution.twoSum(numbers, 0);
	for (int i = 0; i < result.size(); i++) {
		cout << result.at(i) << endl;
	}
}
