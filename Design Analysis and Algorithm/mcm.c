#include <stdio.h>
#include <limits.h>
#define MAX 20

int n;
void matrix_chain(int arr[], int cost[n+1][n+1], int split[n+1][n+1]) {
    // Base case
    for (int i = 1; i <= n; i++) {
        cost[i][i] = 0;
    }

    // Chain length
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;

            // Find minimum cost
            for (int k = i; k < j; k++) {
                int min = cost[i][k] + cost[k + 1][j]
                        + arr[i - 1] * arr[k] * arr[j];

                if (min < cost[i][j]) {
                    cost[i][j] = min;
                    split[i][j] = k;
                }
            }
        }
    }
}

// Print optimal multiplication order
void print_order(int split[n+1][n+1], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_order(split, i, split[i][j]);
        print_order(split, split[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    
    if (n < 1 || n >= MAX) {
        printf("Invalid input!\n");
        return 1;
    }
    int arr[n + 1];
    int cost[n + 1][n + 1];
    int split[n + 1][n + 1];
    printf("Enter %d dimensions:\n", n + 1);

    for (int i = 0; i <= n; i++) {
        printf("p[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    matrix_chain(arr, cost, split);

    printf("Minimum multiplication cost: %d\n", cost[1][n]);

    printf("Optimal order: ");
    print_order(split, 1, n);

    return 0;
}
