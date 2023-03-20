#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() 	
{
    int a[15000];
    clock_t start_t,end_t;
    double total_t;
    for(int i=0;i<15000;i++)
    {
        a[i] = rand();
    }
    start_t = clock();
    selectionSort(a);
    end_t = clock();
    total_t = (double)(end_t - start_t);
    printf("Selection Sort - Average Case\n");
    printf("Total time = %f",total_t);
    return 0;
}

void selectionSort(int a[])
{
    int min,temp;
    for(int i=0;i<15000-1;i++)
    {
        min = i;
        for(int j=i+1;j<15000;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}
