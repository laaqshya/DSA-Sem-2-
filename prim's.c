#include<stdio.h>

#define INF 999

char vertex[10];

void main()
{
    int cost[10][10], visited[10];
    int n, i, j;
    int min, a, b, u, v;
    int ne = 1, mincost = 0;

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
        visited[i] = 0;

    visited[1] = 1;

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
                    if(visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if(visited[u] == 0 || visited[v] == 0)
        {
            printf("Edge %d: (%c - %c) cost = %d\n",
                   ne, vertex[a], vertex[b], min);

            mincost = mincost + min;
            visited[b] = 1;
            ne++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);
}
