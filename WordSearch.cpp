#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    bool exist1(vector<vector<char> > &board, string word) {
		if (word.size() == 0) return true;
		if (board.size() == 0 || board[0].size()==0) return false;

        stack<pair<pair<int,int>,int>> word_stack;
		set<pair<int,int>> pos_set;
		set<pair<int,int>>::iterator it_pos_set;
		int curr_pos = 0;
		char c1 = word.at(curr_pos);
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				char in_c = board[i][j];
				if (in_c != c1) continue;
				if (word.size() == 1) return true;
				pair<int,int> in_pos_set(i,j);
				pair<pair<int,int>,int> word_pair(in_pos_set, 0);
				word_stack.push(word_pair);
				pos_set.insert(in_pos_set);
				curr_pos = 1;
				while (!word_stack.empty()) {
					if (curr_pos > word.size()-1) return true;
					char curr_c = word.at(curr_pos);
					pair<pair<int,int>,int> &in_pair = word_stack.top();
					pair<int,int> in_pos_pair = in_pair.first;
					int dirction = in_pair.second;
					if (dirction >=0 && dirction <=3) {
						dirction += 1; in_pair.second = dirction;
						if (dirction == 1) { //left
							if (in_pos_pair.second==0) continue;
							if (board[in_pos_pair.first][in_pos_pair.second-1] != curr_c) continue;
							it_pos_set = pos_set.find(pair<int,int>(in_pos_pair.first,in_pos_pair.second-1));
							if (it_pos_set != pos_set.end()) continue;
							pair<int,int> left_pos(in_pos_pair.first,in_pos_pair.second-1);
							pair<pair<int,int>,int> tmp_pair(left_pos, 0);
							word_stack.push(tmp_pair);
							pos_set.insert(left_pos);
							curr_pos++;
						} 
						else if (dirction == 2) { //down
							if (in_pos_pair.first==board.size()-1) continue;
							if (board[in_pos_pair.first+1][in_pos_pair.second] != curr_c) continue;
							it_pos_set = pos_set.find(pair<int,int>(in_pos_pair.first+1,in_pos_pair.second));
							if (it_pos_set != pos_set.end()) continue;
							pair<int,int> down_pos(in_pos_pair.first+1,in_pos_pair.second);
							pair<pair<int,int>,int> tmp_pair(down_pos, 0);
							word_stack.push(tmp_pair);
							pos_set.insert(down_pos);
							curr_pos++;
						}
						else if (dirction == 3) { //right
							if (in_pos_pair.second==board[0].size()-1) continue;
							if (board[in_pos_pair.first][in_pos_pair.second+1] != curr_c) continue;
							it_pos_set = pos_set.find(pair<int,int>(in_pos_pair.first,in_pos_pair.second+1));
							if(it_pos_set != pos_set.end()) continue;
							pair<int,int> right_pos(in_pos_pair.first,in_pos_pair.second+1);
							pair<pair<int,int>,int> tmp_pair(right_pos, 0);
							word_stack.push(tmp_pair);
							pos_set.insert(right_pos);
							curr_pos++;
						}
						else if (dirction == 4) { //up
							if (in_pos_pair.first==0) continue;
							if (board[in_pos_pair.first-1][in_pos_pair.second] != curr_c) continue;
							it_pos_set = pos_set.find(pair<int,int>(in_pos_pair.first-1,in_pos_pair.second));
							if (it_pos_set != pos_set.end()) continue;
							pair<int,int> up_pos(in_pos_pair.first-1,in_pos_pair.second);
							pair<pair<int,int>,int> tmp_pair(up_pos, 0);
							word_stack.push(tmp_pair);
							pos_set.insert(up_pos);
							curr_pos++;
						}
					} else {
						word_stack.pop();
						it_pos_set = pos_set.find(in_pos_pair);
						pos_set.erase(it_pos_set);
						curr_pos--;
					}
				}
			}
		}
		return false;
    }

	bool exist(vector<vector<char> > &board, string word) {
		if (word.size() == 0) return true;
		if (board.size() == 0 || board[0].size()==0) return false;

        stack<pair<pair<int,int>,int>> word_stack;
		int rows = board.size(), cols = board[0].size();
		char *sign_arr = new char[rows * cols];
		for (int i =0; i < rows * cols; i++) sign_arr[i] = 0;

		int curr_pos = 0;
		char c1 = word.at(curr_pos);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				char in_c = board[i][j];
				if (in_c != c1) continue;
				if (word.size() == 1) return true;
				pair<int,int> in_pos_set(i,j);
				pair<pair<int,int>,int> word_pair(in_pos_set, 0);
				word_stack.push(word_pair);
				//pos_set.insert(in_pos_set);
				sign_arr[i*cols + j] = 1;
				curr_pos = 1;
				while (!word_stack.empty()) {
					if (curr_pos > word.size()-1) return true;
					char curr_c = word.at(curr_pos);
					pair<pair<int,int>,int> &in_pair = word_stack.top();
					pair<int,int> in_pos_pair = in_pair.first;
					int dirction = in_pair.second;
					if (dirction >=0 && dirction <=3) {
						dirction += 1; in_pair.second = dirction;
						if (dirction == 1) { //left
							if (in_pos_pair.second==0) continue;
							if (board[in_pos_pair.first][in_pos_pair.second-1] != curr_c) continue;							
							if (sign_arr[in_pos_pair.first*cols + in_pos_pair.second-1] == 1) continue;

							pair<int,int> left_pos(in_pos_pair.first,in_pos_pair.second-1);
							pair<pair<int,int>,int> tmp_pair(left_pos, 0);
							word_stack.push(tmp_pair);
							sign_arr[in_pos_pair.first*cols + in_pos_pair.second-1] = 1;
							curr_pos++;
						} 
						else if (dirction == 2) { //down
							if (in_pos_pair.first==board.size()-1) continue;
							if (board[in_pos_pair.first+1][in_pos_pair.second] != curr_c) continue;
							if (sign_arr[(in_pos_pair.first+1)*cols + in_pos_pair.second] == 1) continue;

							pair<int,int> down_pos(in_pos_pair.first+1,in_pos_pair.second);
							pair<pair<int,int>,int> tmp_pair(down_pos, 0);
							word_stack.push(tmp_pair);
							sign_arr[(in_pos_pair.first+1)*cols + in_pos_pair.second] = 1;
							curr_pos++;
						}
						else if (dirction == 3) { //right
							if (in_pos_pair.second==board[0].size()-1) continue;
							if (board[in_pos_pair.first][in_pos_pair.second+1] != curr_c) continue;
							if (sign_arr[in_pos_pair.first*cols + in_pos_pair.second+1] == 1) continue;
							pair<int,int> right_pos(in_pos_pair.first,in_pos_pair.second+1);
							pair<pair<int,int>,int> tmp_pair(right_pos, 0);
							word_stack.push(tmp_pair);
							sign_arr[in_pos_pair.first*cols + in_pos_pair.second+1] = 1;
							curr_pos++;
						}
						else if (dirction == 4) { //up
							if (in_pos_pair.first==0) continue;
							if (board[in_pos_pair.first-1][in_pos_pair.second] != curr_c) continue;
							if (sign_arr[(in_pos_pair.first-1)*cols + in_pos_pair.second] == 1) continue;
							pair<int,int> up_pos(in_pos_pair.first-1,in_pos_pair.second);
							pair<pair<int,int>,int> tmp_pair(up_pos, 0);
							word_stack.push(tmp_pair);
							sign_arr[(in_pos_pair.first-1)*cols + in_pos_pair.second] = 1;
							curr_pos++;
						}
					} else {
						word_stack.pop();
						sign_arr[in_pos_pair.first*cols + in_pos_pair.second] = 0;
						curr_pos--;
					}
				}
			}
		}
		return false;
    }
};

bool wordSearch_test_case1(string find_s) {
	Solution solution;
	
	string s1 = "ABCE", s2 = "SFCS", s3 = "ADEE";
	const char *c1 = s1.c_str(), *c2 = s2.c_str(), *c3 = s3.c_str();
	vector<char> char_vec1(c1,c1+4);
	vector<char> char_vec2(c2,c2+4);
	vector<char> char_vec3(c3,c3+4);

	vector<vector<char>> board;
	board.push_back(char_vec1); board.push_back(char_vec2); board.push_back(char_vec3);
	bool is_word = solution.exist(board, find_s);
	return is_word;
}

int main(int argc, char **argv) {
	//string find_s = "ABCCED";
	//string find_s = "SEE";
	string find_s = "ABCB";
	bool is_word = wordSearch_test_case1("ABCCED");
	is_word = wordSearch_test_case1("SEE");
	is_word = wordSearch_test_case1("ABCB");
	return 0;
}
