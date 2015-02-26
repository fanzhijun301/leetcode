#include<vector>
#include<iostream>
#include<map>
#include<stdio.h>

using namespace std;

struct key_value {
	int key;
	int value;
};

class Solution {
public:
	void sort_1(vector<key_value> &kv_vec) {
		for (int i = 0; i < kv_vec.size() - 1; i++) {
			key_value &kv = kv_vec.at(i);
			int min_value = kv.key;
			int min_index = i;
			for (int j = i; j < kv_vec.size(); j++) {
				key_value kv_in = kv_vec.at(j);
				if (kv_in.key < min_value) {
					min_value = kv_in.key;
					min_index = j;
				}
			}
			if (min_index != i) {
				key_value &kv_min = kv_vec.at(min_index);
				int tmp = kv.key;
				kv.key = kv_min.key;
				kv_min.key = tmp;
				tmp = kv.value;
				kv.value = kv_min.value;
				kv_min.value = tmp;
			}
		}
	}
		
    int candy(vector<int> &ratings) {
    	if (ratings.size() == 0) return 0;
    	else if (ratings.size() == 1) return 1;
    	
//    	multimap<int, int> sort_map;
		vector<key_value> kv_vec;
    	vector<int> candy_vec;
        for (int i = 0; i < ratings.size() - 1; i++) {
        	int r = ratings.at(i);
//        	sort_map.insert(pair<int,int>(r, i));
            key_value kv;
            kv.key = r;
            kv.value = i;
			kv_vec.push_back(kv);
        	candy_vec.push_back(0);
        }
        int total_candy = 0;
        sort_1(kv_vec);
        for (vector<key_value>::iterator it_vec = kv_vec.begin(); it_vec != kv_vec.end(); it_vec++) {
        	key_value kv = *it_vec;
//        	cout << kv.key << " " << kv.value << endl;
        
        	int rate = kv.key;
        	int index = kv.value;
        
        //for (multimap<int,int>::iterator it_map = sort_map.begin(); it_map != sort_map.end(); it_map++) {
//        	int rate = it_map->first;
//			int index = it_map->second;
			
//			cout << rate << " " << index << endl;
			
			int candy_num = 1;
			if (index == 0) {   //only consider right
				int rate_right = ratings.at(index + 1);
				int candy_num_right = candy_vec.at(index + 1);
				if (rate > rate_right) candy_num = candy_num_right + 1;
			}
			else if (index == candy_vec.size() - 1) { //only consider left
				int rate_left = ratings.at(index - 1);
				int candy_num_left = candy_vec.at(index - 1);
				if (rate > rate_left) candy_num = candy_num_left + 1;
			} else {
				int rate_left = ratings.at(index - 1);
				int rate_right = ratings.at(index + 1);
				int candy_num_left = candy_vec.at(index - 1);
				int candy_num_right = candy_vec.at(index + 1);
				int max_rate = (rate_left > rate_right) ? rate_left : rate_right;
				int max_index = (rate_left > rate_right) ? -1 : 1;
				if (rate > max_rate) {
					int max_candy_num = (candy_num_left > candy_num_right) ? candy_num_left : candy_num_right;
					if (max_index == -1) candy_num = max_candy_num + 1;
					else if (max_index == 1) candy_num = max_candy_num + 1;
				} else {
					if ((max_index == -1) && (rate > rate_right)) 
						candy_num = candy_num_right + 1;
					if ((max_index == 1) && (rate > rate_left)) 
						candy_num = candy_num_left + 1; 
				}
			}
			candy_vec.at(index) = candy_num;
			total_candy += candy_num;
//			cout << "======:" << candy_num << endl;
        //}
    	}
        return total_candy;
    }
};


int main(int argc, char **argv) {
//	int myints[] = {32,71,12,12,26,33,53,33};
//	vector<int> myvector (myints, myints+9);
	int myints[] = {2,2};
	vector<int> myvector(myints, myints + 3);
	Solution solution;
	int m = solution.candy(myvector);
	printf("%d\n",m);
}
