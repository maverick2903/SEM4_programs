#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n,v[100],pos,temp;
    int tot_movement=0;
    printf("Enter number of requests\n");
    scanf("%d",&n);
/*     printf("Enter the requests\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    } */
    int req[7] = {82, 170, 43, 140, 24, 16, 190};
    printf("Enter position of head\n");
    scanf("%d",&pos);
    //initial min dist from head
    int min = 9999;
    int init;
    for(int i=0;i<n;i++)
    {
        if(abs(pos-req[i])<min)
        {
            min = abs(pos-req[i]);
            init = i;
        }
    }
    tot_movement += abs(pos - req[init]);
    v[init] = 1;
    printf("min %d\n",req[init]);
    int k = 0;
    
    for(int j=0;j<n;j++)
    {
        int min_diff = 9999;
        for(int i=0;i<n;i++)
        {
            if(abs(req[i]-req[init]) < min_diff && v[i]!=1)
            {
                min_diff = abs(req[i]-req[init]);
                k = i;
            }
        }
        tot_movement += abs(req[init] - req[k]);
        v[k] = 1;
        init = k;
    }


    printf("new min %d\n",init);
    printf("Total distance: %d",tot_movement);
}
