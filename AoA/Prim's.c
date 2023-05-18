#include <stdio.h>
#include <stdlib.h>

#define n 9 //no of nodes
int d [n]; //distance
int p [n]; //parent nodes
int v [n]; //visited
int adj[n][n]= {{0, 11, 0, 0, 0, 0, 0, 8, 0},
                       {11, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
int infinity = 999;

void printSolution()
{
    int sum=0;
    printf("Edge\tWeight\n");
    for (int i = 1; i < n; i++)
     {  
        printf("%d - %d\t\t%d\n", p[i],i,adj[i][p[i]]);
        sum += adj[i][p[i]];
     }
     printf("Sum: %d\n",sum);
}

void relax(int u,int v)
{
    if(d[v]>d[u]+adj[u][v])
    {
        d[v]=d[u]+adj[u][v];
        p[v] = u;
    }
}

int minSet()
{
    int min_index=0;
    int min = 999;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0 && d[i]<=min)
        {
            min = d[i];
            min_index = i;
        }
    }
    return min_index;
}

void initialSet()
{
    for(int i=0;i<n;i++)
    {

            d[i] = infinity;
            p[i] = -1;
            v[i] = 0;
    }
    d[0]=0;
}

void prims()
{
        for(int i=0;i<n;i++)
        {
           int vert = minSet();
           for(int j=0;j<n;j++)
            {
                if(adj[vert][j]!=0)
                {
                    relax(vert,j);
                }
            }
           v[vert] = 1;
        }
}


int main() {
    // printf("Enter the size of matrix : ");
    // scanf("%d",&n);
    // for(int i=0;i<n;i++)
    // {
    //     printf("\nEnter the %d row's weights : ",i+1);
    //     for(int j=0;j<n;j++)
    //     {
    //         scanf("%d",&adj[i][j]);
    //     }
    // }
    
    for(int i=0;i<n;i++)
    {
        v[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    initialSet();
    prims();
    printf("Final Solution\n");
    printSolution();
    return 0;
}
