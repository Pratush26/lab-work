#include <stdio.h>
#include <limits.h>

void swap(int *l, int *r) {
    int t = *l;
    *l = *r;
    *r = t;
}
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int j = l - 1;

    for (int i = l; i < r; i++) {
        if (arr[i] <= pivot) {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[r], &arr[j + 1]);
    return j + 1;
}

void quickSort(int arr[], int l, int r) {
    if (l < r){
        int p = partition(arr, l, r);

        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}
// Sample input
// 5
// 4 2 1 5 3