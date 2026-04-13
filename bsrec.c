#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    if (n == 0)
        return -1;
    if (arr[n - 1] == key)
        return n - 1;
    return linearSearch(arr, n - 1, key);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = 5, key = 8;

    int result = linearSearch(arr, n, key);

    if (result != -1)
        printf("Found at index %d", result);
    else
        printf("Not found");

    return 0;
}