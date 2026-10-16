#include <stdio.h>

int mx;

void countingSort(int arr[], int n, int exp)
{
    int result[n];
    int frq[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        frq[digit]++;
    }

    for (int i = 1; i < 10; i++) frq[i] += frq[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        result[frq[digit] - 1] = arr[i];
        frq[digit]--;
    }

    for (int i = 0; i < n; i++) arr[i] = result[i];
}

void radixSort(int arr[], int n)
{
    for (int i = 1; (mx / i) > 0; i *= 10) countingSort(arr, n, i);
}

int main(void)
{
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");

    scanf("%d", &arr[0]);
    mx = arr[0];

    for (int i = 1; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > mx) mx = arr[i];
    }

    radixSort(arr, n);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}