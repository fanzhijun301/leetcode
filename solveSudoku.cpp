#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<vector>

using namespace std;

class Solution {
	
	int grid[9][9];
	int grid_tt[9][9];
	
	void get_bound(int k, int *b, int *e) {
	    if (k >=0 && k <=2) {*b = 0; *e = 2;}
	    else if (k >= 3 && k <=5) {*b = 3; *e = 5;}
	    else if (k >= 6 && k <=8) {*b = 6; *e = 8;}     
	}

	// at the posion i,j if fill n is ok
	// if return 1, check is ok, else return 0; 
	int check(int i, int j, int n) {
	    int c, che_i, che_j, row_b, row_e, col_b, col_e;
	    //check row
	    for (c = 0; c < 9; c++) { //j
	        if (j != c && grid[i][c] == n) return 0;
	    }
	    //check colomn
	    for (c = 0; c < 9; c++) { //i
	        if (i !=c && grid[c][j] == n) return 0;    
	    }
	    //check inner 9 grid
	    get_bound(i, &row_b, &row_e);
	    get_bound(j, &col_b, &col_e);
	    
	    for (che_i = row_b; che_i <= row_e; che_i++) {
	        for (che_j = col_b; che_j <= col_e; che_j++) {
	            if (i != che_i && j != che_j && grid[che_i][che_j] == n) return 0;
	        }
	    }
	    return 1;
	}
	
	int find_next_pos(int i, int j, int *i_next, int *j_next) {
	    int a,b;
	    for (a = i; a < 9; a++) {
			if (a == i) b = j + 1;
			else b = 0;
			for (; b < 9; b++) {
	     		if (a == 8 && b == 8 && grid_tt[a][b] > 0) return 0;
	     		if (grid_tt[a][b] == 0) {
	      			*i_next = a;
	  				*j_next = b;
	  				return 1;
	     		}
	 		}
	    }
	}
	
	void output_board(vector<vector<char> > &board) {
		for (int i = 0; i < 9; i++) {
			vector<char> &in_v = board.at(i);
			for (int j = 0; j < 9; j++) {
				in_v.at(j) = grid[i][j];
			}
		}
	}
	
	/** fill the position i,j
	    
	**/
	int fill(int i, int j, vector<vector<char> > &board) {
	    int n, c, i_next, j_next, has_np;
	    for (n = 1; n <= 9; n++) {
	        c = check(i, j, n);
	        if (c == 1) {
	            grid[i][j] = n;
	         
	            //find the next pos
	     		i_next = 0; j_next = 0;
	     		has_np = find_next_pos(i, j, &i_next, &j_next);
	     		if (has_np == 1) fill(i_next, j_next, board);
				else output_board(board);
	        } 
	    }
	    grid[i][j] = 0;
	}

public:
    void solveSudoku(vector<vector<char> > &board) {
        int c, i, j, r;        		
		
	    for (i = 0; i < 9; i++) {
	        for (j = 0; j < 9; j++) {
	        	char c = board[i][j];
	        	if (c != '.') {
	        		grid[i][j] = c;
	            	grid_tt[i][j] = c;	
	        	} else {
	        		grid[i][j] = 0;
	            	grid_tt[i][j] = 0;
	        	}
	        }
	    }
	    
	    if (grid_tt[0][0] > 0) r = find_next_pos(0, 0, &i, &j);
    	else {i = 0; j = 0;}
    	
    	fill(i, j, board);
    }
};

void file_init(vector<vector<char> > &board, FILE *src_f) {
    const char *sp = "---------------------";
    int g[9][9], i, j;
    char split[strlen(sp) + 1];
    
    for (i = 0; i < 9; i++) {
		if (i == 3 || i == 6) fscanf(src_f, "%s", split);
    	for (j = 0; j < 9; j++) {
    		if (j == 3 || j == 6) {
				fscanf(src_f, " | %d", &g[i][j]);
     		}
     		else fscanf(src_f, "%d", &g[i][j]);
 		}
    }
    
    for (i = 0; i < 9; i++) {
    	vector<char> &in_vec = board.at(i);
        for (j = 0; j < 9; j++) {
            in_vec.at(j) = g[i][j];
//            printf("%d",g[i][j]);
        }    
//        printf("\n");
    }
}

void output(vector<vector<char> > &board, FILE *f) {
    int i, j;
    for (i = 0; i < 9; i++) {
    	vector<char> in_vec = board.at(i);
        for (j = 0; j < 9; j++) {
        	char c = in_vec.at(j);
            if (j == 0) fprintf(f, "%d", c);
            else if (j == 3 || j == 6){ fprintf(f, " | %d", c); } 
            else fprintf(f, " %d", c);   
        }
        fputs("\n", f);
        if (i == 2 || i == 5) fputs("---------------------\n", f);         
    }
    fputs("\n=======================\n", f);
    fflush(f);
}

int main(int argc, char **argv) 
{
	char *src_file_name, *tgt_file_name;
    FILE *src_f, *tgt_f;
    
	src_file_name = argv[1];
    tgt_file_name = argv[2];
    
    printf("%s\t%s\n", src_file_name, tgt_file_name);
    
    src_f = fopen(src_file_name, "r");
    tgt_f = fopen(tgt_file_name, "w");

	vector<vector<char> > board;
	for (int i = 0; i < 9; i++) {
		vector<char> in_vec;
		for (int j = 0; j < 9; j++) {
			in_vec.push_back(0);
		}
		board.push_back(in_vec);
	}    
    file_init(board, src_f);
    
    Solution solution;
    solution.solveSudoku(board);
    
    for (int i = 0; i < 9; i++) {
		vector<char> in_vec = board.at(i);
		for (int j = 0; j < 9; j++) {
			char c = in_vec.at(j);
			printf("%d",c);
		}
		printf("\n");
	}    
    output(board, tgt_f);
    fclose(src_f);
    fclose(tgt_f);
}
