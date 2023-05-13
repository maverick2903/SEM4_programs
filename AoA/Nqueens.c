#include <stdio.h>
#include <stdlib.h>

int place(int box[],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        if(box[i]==c || abs(box[i]-c)==abs(i-r))
        {
            return 0;
        }
    }
    return 1;
}

void Nqueens(int box[],int r,int n)
{
    for(int c=0;c<n;c++)
    {
        if(place(box,r,c) == 1)
        {
            box[r] = c;
            if(r==n-1)
            {
                for(int k=0;k<n;k++)
                {
                    printf("Queen %d placed at column %d\n",k+1,box[k]+1);
                }
                printf("\n");
            }
            else
            {
                Nqueens(box,r+1,n);
            }
        }
    }
}

void main()
{
    int n,box[100];
    printf("Enter size of board: \n");
    scanf("%d",&n);
    Nqueens(box,0,n);
}
