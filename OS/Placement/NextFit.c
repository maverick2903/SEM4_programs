#include <stdio.h>

void main()
{
    int temp;
    int n_proc=4;
    int n_mem=6;
    int mem_loc[100];
    int visited[100];
    int mem_sizes[] = {200, 400, 600, 500, 300, 250};
    int process_sizes[] = {357, 210, 568, 491};
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
    int last = 0;
    for(int i=0;i<n_proc;i++)
    {
        for(int j=last;j<n_mem;j++)
        {
            if(process_sizes[i] <= mem_sizes[j] && visited[j]==0)
            {
                mem_loc[i] = j;
                visited[j] = 1;
                last = j;
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
