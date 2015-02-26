#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int grid[9][9];
int grid_tt[9][9];

void file_init(FILE *src_f) {
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
     //printf("%d ", g[i][j]);
 		}
 //printf("\n");
    }
    
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            grid[i][j] = g[i][j];
            grid_tt[i][j] = g[i][j];
        }    
    }

}

void init(FILE *src_f) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            grid[i][j] = 0;
        }
    }
    //special_init();
    file_init(src_f);
}

void output(FILE *f) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (j == 0) fprintf(f, "%d", grid[i][j]);
            else if (j == 3 || j == 6){ fprintf(f, " | %d", grid[i][j]); } 
            else fprintf(f, " %d", grid[i][j]);   
        }   
        fputs("\n", f);
        if (i == 2 || i == 5) fputs("---------------------\n", f);         
    }
    fputs("\n=======================\n", f);
    fflush(f);
}

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

/** fill the position i,j
    
**/
int fill(int i, int j, FILE *f) {
    int n, c, i_next, j_next, has_np;
    for (n = 1; n <= 9; n++) {
        c = check(i, j, n);
        if (c == 1) {
            grid[i][j] = n;
         
            //find the next pos
     		i_next = 0; j_next = 0;
     		has_np = find_next_pos(i, j, &i_next, &j_next);
     		if (has_np == 1) fill(i_next, j_next, f);
     		else output(f);
        } 
    }
    grid[i][j] = 0;
}

void test_check() {
    int c, i, j, n;
    
    //for (i = 0; i < 9; i++) {
    //    for (j = 0; j < 9; j++) {
            for (n = 1; n <= 9; n++) {
                c = check(8, 8, n);
                printf("check result: %d,%d\n", n, c);  
                //if (c == 1) printf("%d ", n);
            }   
    //    } 
    //    printf("\n");   
    //}
    
}

void test_read() {
    const char *file = "tmp.txt";
    FILE *f = fopen(file, "r");
    
    file_init(f);
}

int main(int argc, char **argv) {
    int c, i, j, r;
    char *src_file_name, *tgt_file_name;
    FILE *src_f, *tgt_f;
    
    if (argc < 2) {
     	printf("src_file, tgt_file\n");
 		return 1;
    } 
    src_file_name = argv[1];
    tgt_file_name = argv[2];
    
    src_f = fopen(src_file_name, "r");
    tgt_f = fopen(tgt_file_name, "w");
    if (!src_f || !tgt_f) {
        printf("file open err!!\n");
        return 1;  
    }
    init(src_f);
    if (grid_tt[0][0] > 0) r = find_next_pos(0, 0, &i, &j);
    else {i = 0; j = 0;}   

	fill(i, j, tgt_f);
        
    fclose(src_f);
    fclose(tgt_f);
}
