#include <stdio.h>

void countingSort(int arr[], int sortedArr[], int n, int mx)
{
    int frq[mx + 1];

    for (int i = 0; i <= mx; i++) frq[i] = 0;

    for (int i = 0; i < n; i++) frq[arr[i]]++;

    for (int i = 1; i <= mx; i++) frq[i] += frq[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        sortedArr[frq[arr[i]] - 1] = arr[i];
        frq[arr[i]]--;
    }
}

int main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n], sortedArr[n];
    printf("Enter array elements: ");

    scanf("%d", &arr[0]);
    int mx = arr[0];

    for (int i = 1; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > mx) mx = arr[i];
    }
    
    countingSort(arr, sortedArr, n, mx);
    
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", sortedArr[i]);

    return 0;
}