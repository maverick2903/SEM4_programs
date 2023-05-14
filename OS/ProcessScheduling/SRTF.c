#include<stdio.h>

int minBurst(int bt[],int at[],int t,int n)
{
    int min = 999,min_index = -1;
    for(int i=0;i<n;i++)
    {
        if(at[i]<=t && bt[i]<min && bt[i]>0)
        {
            min = bt[i];
            min_index = i;
        }
    }
    return min_index;
}

void main()
{
    int n=4,i,j,count=0,minInd,ind=0,ttat=0,twt=0,t=0;
    float awt,atat;
    int gant[100]={0},cgant[100];
    int pro[]={1,2,3,4};
    int at[]={0,1,2,3};
    int bt[]={18,4,7,2};
    int wt[n],tat[n],rt[n],ct[n],ogbt[n];
    for(i=0;i<n;i++)
    {
        ogbt[i]=bt[i];    
    }
    while(count!=n)
    {
        minInd = minBurst(bt,at,t,n);
        if(pro[minInd]!=gant[ind-1])
        {
            gant[ind] = pro[minInd];
            cgant[ind] = t;
            ind++;
        }
        else
        {
            cgant[ind] = t;
        }
        bt[minInd]--;
        t++;
        if(bt[minInd]==0)
        {
            count++;
            ct[minInd] = t;
            tat[minInd]=ct[minInd]-at[minInd];
            wt[minInd]=tat[minInd]-ogbt[minInd];
            ttat+=tat[minInd];
            twt+=wt[minInd];            
        }
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    printf("\t%d\t%d\t%d\t%d\t%d\t%d\n",pro[i],at[i],ogbt[i],ct[i],tat[i],wt[i]);
    awt=(float)twt/n;
    atat=(float)ttat/n;
    printf("Avg Wait Time %f\nAvg TAT %f\n",awt,atat);
    printf("\nGantt Chart\n");
    for(i=0;i<ind;i++)
    printf("P%d ",gant[i]);
    printf("\n");
    for(i=0;i<ind;i++)
    printf("%d  ",cgant[i]);
    printf("%d ",ct[minInd]);        
}
