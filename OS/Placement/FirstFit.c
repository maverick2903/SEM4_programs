#include <stdio.h>

void main()
{
    int temp;
    int n_proc=4;
    int n_mem=5;
    int mem_loc[100];
    int visited[100];
    int mem_sizes[] = {100, 500, 200, 300, 600};
    int process_sizes[] = {212, 417, 112, 426};
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
    for(int i=0;i<n_mem;i++)
    {
        mem_loc[i] = -1;
    }
    for(int i=0;i<n_proc;i++)
    {
        for(int j=0;j<n_mem;j++)
        {
            if(process_sizes[i] <= mem_sizes[j] && visited[j]==0)
            {
                mem_loc[i] = j;
                visited[j] = 1;
                break;
            }
        }
    }
    printf("\n\n");
    for(int i =0;i<n_proc;i++)
    {
        if(mem_loc[i]!=-1)
        {
            printf("Process size = %d goes in location %d\n",process_sizes[i],mem_sizes[mem_loc[i]]);
        }
        else{printf("%d not allocated to memory\n",process_sizes[i]);}
    }

}
