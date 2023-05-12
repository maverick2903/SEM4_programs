#include<stdio.h>
#include<stdlib.h>
#define n 5
int max,min,a[n];

void minmax(int left,int right)
{
    if(left==right)
    {
        max = min = a[left];
    }
    else if(left==right-1)
    {
        if(a[left]<a[right])
        {
            min = a[left];
            max = a[right];
        }
        else
        {
            max = a[left];
            min = a[right];
        }
    }
    else
    {
        int mid = (left + right)/2;
        minmax(left,mid-1);
        int max1 = max;
        int min1 = min;
        minmax(mid+1,right);
        if(max1> max)
        {
            max = max1;
        }
        if(min1 < min)
        {
            min = min1;
        }
    }
}


void main()
{
    int i;
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        // a[i]=rand()/10000000;
        // printf("%d ",a[i]);
    }
    max=a[0];
    min=a[0];
    minmax(0,n-1);
    printf("\nMax is %d\nMin is %d",max,min);
}
