#include <stdio.h>
#include <limits.h>

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + i + 1];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int x = 0, y = 0;

    for (int i = l; i <= r; i++) {
        if (L[x] <= R[y]) {
            arr[i] = L[x];
            x++;
        }
        else {
            arr[i] = R[y];
            y++;
        }
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}
// Sample input
// 5
// 4 2 1 5 3