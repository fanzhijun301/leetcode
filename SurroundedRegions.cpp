#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
	inline void set_sign(char *sign_arr, int pos) {
		int new_pos = (pos) - (pos) / 8 * 8; 
		char *new_c = sign_arr + (pos)/8; 
		char tmp_c = 1 << (7-new_pos);
		*new_c = *new_c | tmp_c;
	}

	inline char get_sign(char *sign_arr, int pos) {
		int new_pos = (pos) - (pos) / 8 * 8; 
		char tmp_c = sign_arr[(pos)/8]; 
		char new_c = tmp_c >> (7-new_pos); 
		new_c &= 1; 
		return new_c;
	}

    void solve1(vector<vector<char>> &board) {
		if (board.size() < 3 || board[0].size() < 3) return; 
		int cols = board[0].size();
		char *checked = (char *)malloc(sizeof(char) * (board.size() * cols / 8 + 1));
		for (int i =0; i < board.size() * cols / 8 + 1; i++) checked[i] = 0;
		
        queue<pair<int,int>> search_queue;
		bool is_close = true;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				char c = board[i][j];
				if (c == 'X') continue;
				pair<int,int> pos_pair(i,j);
				if (get_sign(checked,i*cols+j) == 1) continue;
				vector<pair<int,int>> keep_vec;
				search_queue.push(pos_pair);
				while(!search_queue.empty()) {
					pair<int,int> in_pos_pair = search_queue.front();
					set_sign(checked,in_pos_pair.first * cols + in_pos_pair.second);
					keep_vec.push_back(in_pos_pair);
					search_queue.pop();
					//up down left right
					if (in_pos_pair.first >= 1) {
						pair<int,int> up_pair(in_pos_pair.first-1,in_pos_pair.second);
						if (board[up_pair.first][up_pair.second] == 'O') {
							if (get_sign(checked,up_pair.first*cols+up_pair.second)==0) search_queue.push(up_pair);
						}
					} else is_close = false;
					if (in_pos_pair.first <= board.size()-2) {
						pair<int,int> down_pair(in_pos_pair.first+1,in_pos_pair.second);
						if (board[down_pair.first][down_pair.second] == 'O') {
							if (get_sign(checked,down_pair.first*cols+down_pair.second)==0) search_queue.push(down_pair);
						}
					} else is_close = false;
					if (in_pos_pair.second >= 1) {
						pair<int,int> left_pair(in_pos_pair.first, in_pos_pair.second-1);
						if (board[left_pair.first][left_pair.second] == 'O') {
							if (get_sign(checked,left_pair.first*cols+left_pair.second)==0) search_queue.push(left_pair);
						}
					} else is_close = false;
					if (in_pos_pair.second <= board[0].size()-2) {
						pair<int,int> right_pair(in_pos_pair.first, in_pos_pair.second+1);
						if (board[right_pair.first][right_pair.second] == 'O') {
							if (get_sign(checked,right_pair.first*cols+right_pair.second)==0) search_queue.push(right_pair);
						}
					} else is_close = false;
				}
				if (is_close) {
					vector<pair<int,int>>::iterator it_vec;
					for (it_vec = keep_vec.begin(); it_vec != keep_vec.end(); it_vec++) {
						pair<int,int> x_pair = *it_vec;
						board[x_pair.first][x_pair.second] = 'X';
					}
				} else keep_vec.clear();
			}
		}
		free(checked);
    }


	void convert_o2c(vector<vector<char>> &board, int i, int j) {
		queue<pair<int,int>> search_queue;
		set<pair<int,int>> search_set;
		set<pair<int,int>>::iterator it_set;
		pair<int,int> pos_pair(i,j);
		vector<pair<int,int>> keep_vec;
		search_queue.push(pos_pair);

		while(!search_queue.empty()) {
			pair<int,int> in_pos_pair = search_queue.front();
			search_set.insert(in_pos_pair);
			keep_vec.push_back(in_pos_pair);
			search_queue.pop();
			//up down left right
			if (in_pos_pair.first >= 1) {
				pair<int,int> up_pair(in_pos_pair.first-1,in_pos_pair.second);
				if (board[up_pair.first][up_pair.second] == 'O') {
					it_set = search_set.find(up_pair);
					if (it_set == search_set.end()) search_queue.push(up_pair);
				}
			}
			if (in_pos_pair.first <= board.size()-2) {
				pair<int,int> down_pair(in_pos_pair.first+1,in_pos_pair.second);
				if (board[down_pair.first][down_pair.second] == 'O') {
					it_set = search_set.find(down_pair);
					if (it_set == search_set.end()) search_queue.push(down_pair);
				}
			}
			if (in_pos_pair.second >= 1) {
				pair<int,int> left_pair(in_pos_pair.first, in_pos_pair.second-1);
				if (board[left_pair.first][left_pair.second] == 'O') {
					it_set = search_set.find(left_pair);
					if (it_set == search_set.end()) search_queue.push(left_pair);
				}
			}
			if (in_pos_pair.second <= board[0].size()-2) {
				pair<int,int> right_pair(in_pos_pair.first, in_pos_pair.second+1);
				if (board[right_pair.first][right_pair.second] == 'O') {
					it_set = search_set.find(right_pair);
					if (it_set == search_set.end()) search_queue.push(right_pair);
				}
			}
		}
		vector<pair<int,int>>::iterator it_vec;
		for (it_vec = keep_vec.begin(); it_vec != keep_vec.end(); it_vec++) {
			pair<int,int> x_pair = *it_vec;
			board[x_pair.first][x_pair.second] = 'C';
		}
	}
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() < 3 || board[0].size() < 3) return; 
        
		//top
		for (int i = 0; i < board[0].size(); i++) 
			if (board[0][i] == 'O') board[0][i] = 'C';
		//left
		for (int i = 0; i < board.size(); i++) 
			if (board[i][0] == 'O') board[i][0] = 'C';
		//down
		for (int i = 0; i < board[0].size(); i++) 
			if (board[board.size()-1][i] == 'O') board[board.size()-1][i] = 'C';
		//right
		for (int i = 0; i < board.size(); i++) 
			if (board[i][board[0].size()-1] == 'O') board[i][board[0].size()-1] = 'C';

		for (int i = 1; i < board.size(); i++) {
			for (int j = 1; j < board[0].size(); j++) {
				if (board[i][j] == 'X') continue;
				if (board[i][j-1] == 'C' || board[i-1][j] == 'C') board[i][j] = 'C';
			}
		}
		for (int i = board.size()-2; i >= 0; i--) {
			for (int j = board[0].size() - 2; j >= 0; j--) {
				if (board[i][j] == 'X') continue;
				if (board[i][j+1] == 'C' || board[i+1][j] == 'C') board[i][j] = 'C';
			}
		}
		for (int i = 1; i < board.size() - 1; i++) {
			for (int j = 1; j < board[0].size() - 1; j++) {
				if (board[i][j] == 'O') {
					if (board[i-1][j] == 'C' || board[i+1][j] == 'C' || board[i][j-1] == 'C' || board[i][j+1] == 'C')
						convert_o2c(board, i, j);
				}
			}
		}

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				char c = board[i][j];
				if (c == 'O') board[i][j] = 'X';
				else if (c == 'C') board[i][j] = 'O';
			}
		}
    }
};

void SurroundedRegions_test_case1() {
	int len = 4;
	char arr1[] = {'X','X','X','X'};
	char arr2[] = {'X','O','O','X'};
	char arr3[] = {'X','X','O','X'};
	char arr4[] = {'X','O','X','X'};

	vector<char> vec1(arr1, arr1 + len);
	vector<char> vec2(arr2, arr2 + len);
	vector<char> vec3(arr3, arr3 + len);
	vector<char> vec4(arr4, arr4 + len);

	vector<vector<char>> board;
	board.push_back(vec1); board.push_back(vec2);
	board.push_back(vec3); board.push_back(vec4);
	
	Solution solution;
	solution.solve(board);
	for (int i = 0; i < board.size(); i++) {
		vector<char> in_vec = board[i];
		for (int j = 0; j < in_vec.size(); j++) {
			cout << " " << in_vec[j];
		}
		cout << endl;
	}
}

void SurroundedRegions_test_case2() {
	int len = 1;
	//char arr1[] = {'X'};
	char arr1[] = {'O'};
	vector<char> vec1(arr1, arr1 + len);

	vector<vector<char>> board;
	board.push_back(vec1); 
	
	Solution solution;
	solution.solve(board);
	for (int i = 0; i < board.size(); i++) {
		vector<char> in_vec = board[i];
		for (int j = 0; j < in_vec.size(); j++) {
			cout << " " << in_vec[j];
		}
		cout << endl;
	}
}

inline void set_sign(char *sign_arr, int pos) {
	int new_pos = (pos) - (pos) / 8 * 8; 
	char *new_c = sign_arr + (pos)/8; 
	char tmp_c = 1 << (7-new_pos);
	*new_c = *new_c | tmp_c;
}

inline char get_sign(char *sign_arr, int pos) {
	int new_pos = (pos) - (pos) / 8 * 8; 
	char tmp_c = sign_arr[(pos)/8]; 
	char new_c = tmp_c >> (7-new_pos); 
	new_c &= 1; 
	return new_c;
}

void cacu_byte() {
	int len = 25;
	char *sign_arr = new char[len / 8 + 1];
	for (int i = 0; i < len / 8 + 1; i++) sign_arr[i] = 0;
	
	int pos = 10;
	for (int i = 3; i < len - 3; i++) set_sign(sign_arr, i);
	
	for (int i = 0; i < len; i++) {
		char new_c = get_sign(sign_arr, i);
		printf("%d,%d\n",i,new_c);
	}
	printf("haha\n");
}
#undef set_sign(pos)

int main_surroundedRe(int argc,char **argv) {
	SurroundedRegions_test_case1();
	SurroundedRegions_test_case2();
	//cacu_byte();
	return 0;
}