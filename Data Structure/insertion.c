#include <stdio.h>

int main() {
    int n, k, val;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &k, &val);
    int i = n;
    n++;
    while (k < i)
    {
        arr[i] = arr[i-1];
        i--;
    }
    arr[k] = val;
    i = 0;
    while (i < n)
    {
        printf("%d ", arr[i]);
        i++;
    }
    return 0;
}
// Sample input
// 5
// 4 2 1 5 3
// 2 6