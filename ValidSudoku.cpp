#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        //rows
		for (int i = 0; i < 9; i++) {
			vector<char> in_vec = board[i];
			vector<char> sign(9,'0');
			for (int j =0; j < in_vec.size(); j++) {
				char c = in_vec[j];
				if (c == '.') continue;
				if (sign[c-'1'] == '1') return false;
				sign[c-'1'] = '1';
			}
		}
		//cols
		for (int i = 0; i < 9; i++) {
			vector<char> sign(9,'0');
			for (int j = 0; j < 9; j++) {
				char c = board[j][i];
				if (c == '.') continue;
				if (sign[c-'1'] == '1') return false;
				sign[c-'1'] = '1';
			}
		}
		//9
		for (int t = 0; t < 3; t++) {
			for (int k=0; k < 3; k++) {
				vector<char> sign(9,'0');
				for (int i=t*3; i<t*3+3; i++) {
					for (int j=0; j<=2; j++) {
						int col = k * 3 + j;
						char c = board[i][col];
						if (c == '.') continue;
						if (sign[c-'1'] == '1') return false;
						sign[c-'1'] = '1';
					}
				}
			}
		}
		return true;
    }
};

void isValidSudoku_test_case1() {
	char c1[] = {'5','3','.', '.','7','.', '.','.','.'};
	char c2[] = {'6','.','.', '1','9','5', '.','.','.'};
	char c3[] = {'.','9','8', '.','.','.', '.','6','.'};

	char c4[] = {'8','.','.', '.','6','.', '.','.','3'};
	char c5[] = {'4','.','.', '8','.','6', '.','.','1'};
	char c6[] = {'7','.','.', '.','2','.', '.','.','6'};

	char c7[] = {'.','6','.', '.','.','.', '2','8','.'};
	char c8[] = {'.','.','.', '4','1','9', '.','.','5'};
	char c9[] = {'.','.','.', '.','8','.', '.','7','9'};

	vector<char> vec1(c1,c1+9),vec2(c2,c2+9),vec3(c3,c3+9);
	vector<char> vec4(c4,c4+9),vec5(c5,c5+9),vec6(c6,c6+9);
	vector<char> vec7(c7,c7+9),vec8(c8,c8+9),vec9(c9,c9+9);
	vector<vector<char>> board;
	board.push_back(vec1); board.push_back(vec2); board.push_back(vec3);
	board.push_back(vec4); board.push_back(vec5); board.push_back(vec6);
	board.push_back(vec7); board.push_back(vec8); board.push_back(vec9);
	Solution solution;
	bool is_valid = solution.isValidSudoku(board);
	cout << is_valid << endl;
}

int main_validSudoku(int argc, char **argv) {
	isValidSudoku_test_case1();
	return 0;
}