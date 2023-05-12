#include <stdio.h>
#include <stdlib.h>

int n=9; //no of nodes
int d [9]; //distance
int p [9]; //parent nodes
int v [9]; //visited
int adj[9][9]= { { 0, 11, 0, 0, 0, 0, 0, 8, 0 },
                { 11, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
                };
int infinity = 999;

void printSolution()
{
    printf("Vertex\tDist\tParent\n");
    for (int i = 0; i < n; i++)
     {  
        printf("%d\t\t%d\t\t%d\n", i, d[i],p[i]);
     }
}

void relax(int u,int v)
{
    if(d[v]>d[u]+adj[u][v])
    {
        d[v]=d[u]+adj[u][v];
        p[v] = u;
    }
}

int findMin()
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

void djikstra()
{
        for(int i=0;i<n;i++)
        {
           int vert = findMin();
           printf("For vertex: %d\n",vert);
           for(int j=0;j<n;j++)
            {
                if(adj[vert][j]!=0)
                {
                    relax(vert,j);
                }
            }
           v[vert] = 1;
           printSolution();
           printf("\n");
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
    djikstra();
    printf("Final Solution\n");
    printSolution();
    return 0;
}
