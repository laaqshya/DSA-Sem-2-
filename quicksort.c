#include <stdio.h>

int partition(int a[], int l, int h) {
    int p=a[l];
    int i=l+1,j=h,t;
    while (1) {
        while (i<=h && a[i]<=p) 
		i++;
        while (a[j]>p) 
		j--;
        if (i < j) {
            t=a[i];
            a[i]=a[j];
            arr[j]=t;
        } 
		else
		break;
    }
    t=a[l];
    a[l]=a[j];
    a[j]=t;
    return j;
}
void quicksort(int a[], int l, int h) {
    if (l<h) {
        int j = partition(a,l,h);
        quicksort(a,l,j-1);
        quicksort(a,j+1,h);
    }
}
int main() {
    int a[10],n,i;
    printf("enter n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    quicksort(a,0,n - 1);
    for (i= 0;i<n; i++)
        printf("%d ",a[i]);
    return 0;
}
