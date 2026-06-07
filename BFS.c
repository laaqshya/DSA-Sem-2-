#include<stdio.h>

char queue[10];
int front=0,rear=-1;

void insert(char c){
    queue[++rear]=c;
}

char delete(){
    return queue[front++];
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
        printf("%c ",g[i]);
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

    insert(g[i]);
    status[i]=2;

    printf("BFS traversal: ");

    while(front<=rear){
        c=delete();

        for(i=0;i<n;i++){
            if(c==g[i]){
                break;
            }
        }

        printf("%c ",c);
        status[i]=3;

        for(j=0;j<n;j++){
            if(a[i][j]==1 && status[j]==1){
                insert(g[j]);
                status[j]=2;
            }
        }
    }

    return 0;
}
