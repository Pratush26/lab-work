#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    printf("Enter index for deleting: ");
    scanf("%d", &k);
    n--;
    int i = k;
    while (i <= n)
    {
        arr[i] = arr[i+1];
        i++;
    }
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
// 2