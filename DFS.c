#include<stdio.h>

char stack[10];
int top=-1;

void push(char c){
    stack[++top]=c;
}

char pop(){
    return stack[top--];
}

int main(){
    int n,a[10][10],i,j,status[10];
    char g[10],c;

    printf("enter no. of vertices:");
    scanf("%d",&n);

    printf("enter the vertices:\n");
    for(i=0;i<n;i++){
        scanf(" %c",&g[i]);
    }

    printf("adjacency matrix:\n");
    printf("  ");
    for(i=0;i<n;i++){
        printf(" %c ",g[i]);
        status[i]=1;
    }
    printf("\n");

    for(i=0;i<n;i++){
        printf(" %c ",g[i]);
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("enter starting vertex:");
    scanf(" %c",&c);

    for(i=0;i<n;i++){
        if(c==g[i]){
            break;
        }
    }

    push(g[i]);
    status[i]=2;

    printf("DFS traversal: ");

    while(top!=-1){
        c=pop();

        for(i=0;i<n;i++){
            if(c==g[i]){
                break;
            }
        }

        if(status[i]!=3){
            printf("%c ",c);
            status[i]=3;
        }

        for(j=n-1;j>=0;j--){
            if(a[i][j]==1 && status[j]==1){
                push(g[j]);
                status[j]=2;
            }
        }
    }

    return 0;
}
