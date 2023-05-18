#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() 
{
    int a[15000];
    clock_t start_t,end_t;
    double avg,best,worst;
    
    for(int i=0;i<15000;i++){
        a[i] = i;
    }
    start_t = clock();
    insertionSort(a);
    end_t = clock();
    best = (double)(end_t - start_t);
    printf("Insertion Sort - Best Case\n");
    printf("Total time = %f\n",best);
    
    for(int i=0;i<15000;i++){
        a[i] = rand();
    }
    start_t = clock();
    insertionSort(a);
    end_t = clock();
    avg = (double)(end_t - start_t);
    printf("Insertion Sort - Average Case\n");
    printf("Total time = %f\n",avg);
    
    for(int i=0;i<15000;i++){
        a[i] = 14999-i;
    }
    start_t = clock();
    insertionSort(a);
    end_t = clock();
    worst = (double)(end_t - start_t);
    printf("Insertion Sort - Worst Case\n");
    printf("Total time = %f\n",worst);    
    return 0;
}

void insertionSort(int a[])
{
    int j,key;
    for(int i=0;i<15000;i++)
    {
        j = i-1;
        key = a[i];
        while(a[j]>key && j>-1)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
