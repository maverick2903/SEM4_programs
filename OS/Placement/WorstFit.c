#include <stdio.h>

void main()
{
    int temp;
    int n_proc=4;
    int n_mem=6;
    int mem_loc[100];
    int visited[100];
    int mem_sizes[] = {200, 400, 600, 500, 300, 250};
    int process_sizes[] = {357, 210, 468, 491};
    /*int process_sizes[100];
    int mem_sizes[100];
    printf("Enter no of memory partitions\n");
    scanf("%d",&n_mem);
    printf("Enter size\n");
    for(int i=0;i<n_mem;i++)
    {
        scanf("%d",&mem_sizes[i]);
    }
    printf("Enter no of processes\n");
    scanf("%d",&n_proc);
    printf("Enter size\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&process_sizes[i]);
    } */

    for(int i=0;i<n_mem;i++)
    {
        visited[i] = 0;
    }

    for(int i=0;i<n_mem-1;i++)
    {
        for(int j=i+1;j<n_mem;j++)
        {
            if(mem_sizes[i]<mem_sizes[j])
            {
                temp = mem_sizes[i];
                mem_sizes[i] = mem_sizes[j];
                mem_sizes[j] = temp;
            }
        }
    }

    int index = 0;
    for(int i=0;i<n_proc;i++)
    {
        if(process_sizes[i] <= mem_sizes[index])
        {
            mem_loc[i] = index;
            index++;            
        }
        else{
            mem_loc[i] = -1;
        }
    }
    for(int i =0;i<n_proc;i++)
    {
        if(mem_loc[i]!=-1)
        {
            printf("Process size = %d goes in location %d\n",process_sizes[i],mem_sizes[mem_loc[i]]);
        }
        else{printf("%d not allocated to memory\n",process_sizes[i]);}
    }
}
