#include<stdio.h>

#define INF 999

int parent[10];
char vertex[10];

int find(int i)
{
    while(parent[i] != 0)
        i = parent[i];

    return i;
}

int uni(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }

    return 0;
}

void main()
{
    int cost[10][10];
    int n, i, j;
    int a, b, u, v;
    int min, ne = 1, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the vertices:\n");
    for(i = 1; i <= n; i++)
    {
        scanf(" %c", &vertex[i]);
    }

    printf("\nEnter cost adjacency matrix:\n");
    printf("Enter 999 if there is no edge\n\n");

    printf("   ");
    for(i = 1; i <= n; i++)
        printf("%c   ", vertex[i]);

    printf("\n");

    for(i = 1; i <= n; i++)
    {
        printf("%c  ", vertex[i]);

        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    for(i = 1; i <= n; i++)
        parent[i] = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(ne < n)
    {
        min = INF;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(uni(u, v))
        {
            printf("Edge %d: (%c - %c) cost = %d\n",
                   ne, vertex[a], vertex[b], min);

            mincost = mincost + min;
            ne++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);
}
