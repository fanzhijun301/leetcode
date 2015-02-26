#include<iostream>
#include<map>

using namespace std;
 
class Solution {
public:
    int singleNumber(int A[], int n) {
        map<int, int> stat_map;
        for (int i = 0; i < n; i++) {
        	int a = A[i];
        	map<int, int>::iterator it_map = stat_map.find(a);
        	if (it_map == stat_map.end()) {
        		stat_map[a] = 0;
        		it_map = stat_map.find(a);
        	}
        	int stat = it_map->second;
        	stat_map[a] = stat + 1;
        }
        map<int, int>::iterator it_map;
        for (it_map = stat_map.begin(); it_map != stat_map.end(); it_map++) {
        	int a = it_map->first;
        	int stat = it_map->second;
        	if (stat == 1) return a;
        }
    }
};

int main(int argc, char **argv) {
	Solution solution;
	int *A = new int[9];
	A[0] = 1; A[1] = 1; A[2] = 2; A[3] = 2; A[4] = 3; A[5] = 3;
	A[6] = 4; A[7] = 4; A[8] = 5;
	int single = solution.singleNumber(A, 10);
	cout << single << endl;
}
