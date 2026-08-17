#include <stdio.h>

int main() {
    int n, item;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &item);

    int beg = 0, end = n-1, mid;
    while (beg <= end)
    {
        mid = (beg+end)/2;
        if(item < arr[mid]) end = mid - 1;
        else beg = mid + 1;
    }
    if(arr[mid] == item) printf("The index of %d = %d", item, mid);
    else printf("Item not Found!");
    return 0;
}
// Sample input
// 5
// 1 2 3 4 5
// 5