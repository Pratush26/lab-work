#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int i = 0;
    while (i < n)
    {
        printf("%d ", arr[i]);
        i++;
    }
    return 0;
}