
#include <stdio.h>
#include <string.h>
#define MAX 100

int m, n, c[MAX][MAX];
char b[MAX][MAX];

void lcs_length(char *X, char *Y) {
    for (int i = 1; i <= m; i++) c[i][0] = 0;
    for (int j = 0; j <= n; j++) c[0][j] = 0;

    // The DP Matrix Core loops 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i] == Y[j]) {                      
                c[i][j] = c[i - 1][j - 1] + 1;      
                b[i][j] = 'D';                      //('D' = Diagonal ↖)
            }
            else if (c[i - 1][j] >= c[i][j - 1]) {  
                c[i][j] = c[i - 1][j];              
                b[i][j] = 'U';                      //('U' = Up ↑)
            }
            else {
                c[i][j] = c[i][j - 1];             
                b[i][j] = 'L';                      //('L' = Left ←)
            }
        }
    }
}

// Second Algorithm: Recursively backtracks and prints the string sequence
void print_lcs(char *X, int i, int j) {
    if (i == 0 || j == 0) return;
    
    if (b[i][j] == 'D') {
        print_lcs(X, i - 1, j - 1);
        printf("%c", X[i]);            
    }
    else if (b[i][j] == 'U') print_lcs(X, i - 1, j);
    else print_lcs(X, i, j - 1);
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";
    m = strlen(X);
    n = strlen(Y);

    // Shift strings right by 1 index to align with 1-based indexing in slides
    char X_shifted[MAX] = " ";
    char Y_shifted[MAX] = " ";
    strcat(X_shifted, X);
    strcat(Y_shifted, Y);

    printf("Sequence X: %s\n", X);
    printf("Sequence Y: %s\n\n", Y);

    // Step 1: Run LCS-Length to populate the matrices
    lcs_length(X_shifted, Y_shifted);

    // Step 2: Output the results
    printf("Length of LCS: %d\n", c[m][n]);
    printf("Longest Common Subsequence: ");
    print_lcs(X_shifted, m, n);
    printf("\n");

    return 0;
}