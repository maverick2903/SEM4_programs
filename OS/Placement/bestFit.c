#include <stdio.h>

void main()
{
    int n;
    //int process_sizes[100];
    int n_mem;
    //int mem_sizes[100];
    int mem_loc[100];
    printf("Enter no of memory partitions\n");
    scanf("%d",&n_mem);
    int mem_sizes[] = {200, 400, 600, 500, 300, 250};
    int process_sizes[] = {357, 210, 468, 491};
    /* printf("Enter size\n");
    for(int i=0;i<n_mem;i++)
    {
        scanf("%d",&mem_sizes[i]);
    } */
    printf("Enter no of processes\n");
    scanf("%d",&n);
    /* printf("Enter size\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&process_sizes[i]);
    } */

    int k = 0;
    for(int i=0;i<n;i++)
    {
        int min_diff = 9999;
        for(int j=0;j<n_mem;j++)
        {
            if(mem_sizes[j]-process_sizes[i]<min_diff && mem_sizes[j]-process_sizes[i]>=0)
            {
                min_diff = mem_sizes[j]-process_sizes[i];
                mem_loc[k] = j;
            }
        }
        k++;
    }
    for(int i =0;i<n;i++)
    {
        if(mem_loc[i])
        {
            printf("Process size = %d goes in location %d\n",process_sizes[i],mem_sizes[mem_loc[i]]);
        }
        else{printf("%d not allocated to memory",process_sizes[i]);}
    }
}
