#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    	if (gas.size() == 1) {
    		if (gas.at(0) >= cost.at(0)) return 0;
    	}
        vector<int> middle_vec;
        int total_middle = 0;
        int a_idx = 0;
        int b_idx = 0;
        for (int i = 0; i < gas.size(); i++) {
        	int keep = gas[i] - cost[i];
        	total_middle += keep;
        	middle_vec.push_back(keep);
        	if (keep >= 0) {
        		a_idx = i;
        		b_idx = i + 1;
        		if (i == gas.size() - 1) b_idx = 0;
        	}
        }
        if (total_middle < 0) return -1;  
		        
        int sum = middle_vec.at(a_idx);
        while (a_idx != b_idx) {
//        	cout << a_idx << " " << b_idx << " " << sum << endl;
        	while (true) {
        		if (sum + middle_vec.at(b_idx) >= 0) {   //check wether you can go further
        			sum += middle_vec.at(b_idx);
        			b_idx += 1;
        			if (b_idx == gas.size()) b_idx = 0;
        			if (a_idx == b_idx) {
        				if (sum >= 0)return a_idx;
        				else return -1;
        			}
        		} else {
        			break;
        		}
        	}
        	while (true) {
        		int tmp_a_idx = a_idx - 1;
        		if (a_idx == 0) {
        			tmp_a_idx = gas.size() - 1;
        		}
        		if (tmp_a_idx == b_idx) {
        			sum += middle_vec.at(b_idx);
        			if (sum >= 0) return b_idx;
        			else return -1;
        		}
        		if (sum + middle_vec.at(tmp_a_idx) + middle_vec.at(b_idx) < 0) {
        			a_idx -= 1;
        			if (a_idx == -1) a_idx = gas.size() - 1;
        			sum += middle_vec.at(a_idx);
        		} else {
        			a_idx -= 1;
        			if (a_idx == -1) a_idx = gas.size() - 1;
        			sum += middle_vec.at(a_idx);
        			break;
        		}
        	}
        }
    }
};

int main(int argc, char **argv) {
	Solution solution;
	vector<int> gas; vector<int> cost;
//	gas.push_back(4);	cost.push_back(5);
//	gas.push_back(9);	cost.push_back(10);
//	gas.push_back(17);	cost.push_back(7);
//	gas.push_back(5);	cost.push_back(6);
//	gas.push_back(10);	cost.push_back(9);

	gas.push_back(1);	cost.push_back(2);
	gas.push_back(2);	cost.push_back(1);
	int r = solution.canCompleteCircuit(gas, cost);
	cout << r << endl;
}
