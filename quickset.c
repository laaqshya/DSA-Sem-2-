#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high, temp;

    while (1) {
        while (i <= high && arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else break;
    }

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}