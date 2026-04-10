#include <stdio.h>

void ssort(int a[], int n, int i);

int main() {
    int a[50], n, i;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    ssort(a, n, 0);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void ssort(int a[], int n, int i) {
    int j, min, temp;
    // Base case
    if (i >= n - 1)
        return;
    min=i;
    // Find index of minimum element
    for (j = i + 1; j < n; j++) {
        if (a[j]<a[min]) {
            min=j;
        }
    }
    // Swap
    if (min!=i) {
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    // Recursive call
    ssort(a, n, i + 1);
}
