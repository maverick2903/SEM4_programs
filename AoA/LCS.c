#include <stdio.h>
#include <string.h>
#define m 11
#define n 11
char *x = "properties";
char *y = "prosperity";

int c [m][n];
char b [m-1][n-1];

int main()
{
    LCS_length();
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    int i=10,j=10;
    print_LCS(i-1,j-1);
    return 0;
}

void LCS_length()
{
    int i,j;
    c[0][0] = 0;
    for(i=0;i<=m;i++)
    {
        c[i][0] = 0;
    }
    for(j=0;j<=n;j++)
    {
        c[0][j] = 0;
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i-1][j-1] = '*';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i-1][j-1] = '^';
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i-1][j-1] = '<';
            }
        }
    }
}

void print_LCS(int i,int j)
{
    if(i==-1 || j==-1)
    {
        return;
    }
    if(b[i][j]=='*')
    {
        print_LCS(i-1,j-1);
        printf("%c",x[i]);
    }
    else if(b[i][j]=='^')
    {
        // printf("c\n");
        print_LCS(i-1,j);
    }
    else
    {
        // printf("c\n");
        print_LCS(i,j-1);
    }
}