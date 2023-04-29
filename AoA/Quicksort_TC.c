#include <stdio.h>
#include <stdlib.h>
#include<time.h>
float s,e,t,s2,e2,t2,s3,e3,t3;
// Partition using Hoare's Partitioning scheme
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while (1)
    {
        do {
            i++;
        } while (a[i] < pivot);
 
        do {
            j--;
        } while (a[j] > pivot);
 
        if (i >= j) {
            return j;
        }
 
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
 
// Quicksort routine
void quicksort(int a[], int low, int high)
{
    // base condition
    if (low < high) {
        // rearrange elements across pivot
    int pivot = partition(a, low, high);
 
    // recur on subarray containing elements that are less than the pivot
    quicksort(a, low, pivot);
 
    // recur on subarray containing elements that are more than the pivot
    quicksort(a, pivot + 1, high);
    }
}

int main() 
{
    int i,a[50000],b[50000],c[50000],n;
    printf("enter the value of n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=i;
    }
    s=clock();
    quicksort(a,0,n-1);
    e=clock();
    t=(float)(e-s);
    printf("\nBEST CASE:%f",t);
    for(i=0;i<n;i++)
    {
        b[i]=rand();
    }
    s2=clock();
    quicksort(b,0,n-1);
    e2=clock();
    t2=(float)(e2-s2);
    printf("\nAVERAGE CASE:%f",t2);
    for(i=0;i<n;i++)
    {
        c[i]=i;
    }
    s3=clock();
    quicksort(c,0,n-1);
    e3=clock();
    t3=(float)(e3-s3);
    printf("\nWORST CASE:%f",t3);
}
