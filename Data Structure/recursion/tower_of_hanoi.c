#include <stdio.h>

void toh(int n, char beg, char aux, char end){
    if(n <= 1){
        if(n == 1) printf("%c -> %c\n", beg, end);
        return;
    }
    toh(n-1, beg, end, aux);
    printf("%c -> %c\n", beg, end);
    toh(n-1, aux, beg, end);
}
int main() {
    int n;
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
    return 0;
}