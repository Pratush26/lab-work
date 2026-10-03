#include <stdio.h>

void fib(int prev, int sum, int cur, int n){
    if(cur == n) return;
    printf("%d ", sum);
    fib(sum, prev+sum, cur+1, n);
}
int main() {
    int n;
    scanf("%d", &n);
    fib(0, 1, 0, n);
    return 0;
}