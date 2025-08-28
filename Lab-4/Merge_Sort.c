#include <stdio.h>
#define MAX 100

void merge(int arr[], int low, int mid, int high) {
    int temp[MAX];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] > arr[j]) {
            temp[k++] = arr[j++];
        } else {
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= high) {
        temp[k++] = arr[j++];
    }
    for (i = 0; i < k; i++) {
        arr[low + i] = temp[i];
    }
}

void merge_sort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int n, i, arr[MAX];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
