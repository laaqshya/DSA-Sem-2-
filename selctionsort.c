#include <stdio.h>
int main() {
    int a[50], n, i, j, min, t;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements of array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Selection Sort
    for(i=1;i<n;i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        t= a[i];
        a[i] = a[min];
        a[min] = t;
    }
    printf("Sorted array:\n");
    for(i=0;i<n;i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
