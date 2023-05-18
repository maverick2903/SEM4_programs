#include <stdio.h>
#define n 5
int adj[n][n] ={{0, 6, 0, 7, 0},  //s
              {0, 0, 5, 8, -4}, //t
              {0, -2, 0, 0, 0}, //x
              {0, 0, -3, 0, 9}, //y          
              {2, 0, 7, 0, 0}}; //z
int d[n],p[n];
int inf = 999;

void printAns()
{
    printf("Vertex\tDist\tParent\n");
    for (int i = 0; i < n; i++)
     {  
        printf("%d\t\t%d\t\t%d\n", i, d[i],p[i]);
     }
}

void initialSet()
{
    for(int i=0;i<n;i++)
    {
        d[i] = inf;
        p[i] = -1;
    }
    d[0] = 0;
}

void bellmanFord()
{
    for(int u=0;u<n;u++)
    {
        for(int v=0;v<n;v++)
        {
            if(adj[u][v]!=0 && d[v]>d[u]+adj[u][v])
            {
                d[v] = d[u]+adj[u][v];
                p[v] = u;
            }
        }
    }
}

void main()
{
    initialSet();
    for(int i=0;i<n-1;i++)
    {
        bellmanFord();
    }
    // Perform one more iteration to check negative cycle 
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && d[v] > d[u] + adj[u][v]) {
                printf("Negative cycle detected!\n");
                return;
            }
        }
    }
    printf("No negative cycle detected.\n");
    printAns();
}
