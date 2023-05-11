#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n,req[100],pos,total,temp;
    char dir ='u';
    int tot_movement;
    printf("Enter number of requests\n");
    scanf("%d",&n);
    printf("Enter the requests\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter position of head\n");
    scanf("%d",&pos);
    printf("Enter track end number\n");
    scanf("%d",&total);
    //Sorting req in ascending order
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(req[i]>req[j])
            {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }
    //Finding the process less than and closest to head (will be greater than and closest to if direction is down)
    int min = 9999;
    int last_index = 0;
    if(dir=='u')
    {
        for(int i=0;i<n;i++)
        {
            if(req[i]<pos && abs(req[i]-pos)<=min)
            {
                min = abs(req[i]-pos);
                last_index = i;
            }
            else{
                break;
            }
        }
        tot_movement = 2*total - pos + req[last_index];
    }
    printf("Total track movement = %d",tot_movement);
}
