#include <stdio.h>

void main()
{
    int n_proc;
    //int process_sizes[100];
    int n_mem;
    //int mem_sizes[100];
    int mem_loc[100];
    int visited[100];
    int mem_sizes[] = {200, 400, 600, 500, 300, 250};
    int process_sizes[] = {357, 210, 468, 491};
    printf("Enter no of memory partitions\n");
    scanf("%d",&n_mem);
    /* printf("Enter size\n");
    for(int i=0;i<n_mem;i++)
    {
        scanf("%d",&mem_sizes[i]);
    } */
    printf("Enter no of processes\n");
    scanf("%d",&n_proc);
    /* printf("Enter size\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&process_sizes[i]);
    } */

    for(int i=0;i<n_mem;i++)
    {
        visited[i] = 0;
    }

    int mem_index = 0;
    for(int i=0;i<n_proc;i++)
    {
        int min_diff = 9999;
        for(int j=0;j<n_mem;j++)
        {
            if(mem_sizes[j]-process_sizes[i]<min_diff && mem_sizes[j]-process_sizes[i]>=0 && visited[j]==0)
            {
                min_diff = mem_sizes[j]-process_sizes[i];
                mem_loc[mem_index] = j;
            }
        }
        visited[mem_loc[mem_index]] = 1;
        mem_index++;
    }
    for(int i =0;i<n_proc;i++)
    {
        if(mem_loc[i])
        {
            printf("Process size = %d goes in location %d\n",process_sizes[i],mem_sizes[mem_loc[i]]);
        }
        else{printf("%d not allocated to memory",process_sizes[i]);}
    }
}
