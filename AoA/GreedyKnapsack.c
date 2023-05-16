#include <stdio.h>

int main() 
{
    int n = 5;
    int place[100] = {0,0,0,0};
    float frac[100] = {0,0,0,0};
    float profit;
    int wt[] = {5, 10, 15, 22, 25};
    int pr[] = {30, 40, 45, 77, 90};
    float pw[100];
    int W = 60;
    for(int i=0;i<n;i++)
    {
        pw[i] = (float)pr[i]/wt[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(pw[j]>pw[i])
            {
                float temp = pw[i];
                pw[i] = pw[j];
                pw[j] = temp;
                int temp2 = pr[i];
                pr[i] = pr[j];
                pr[j] = temp2;
                int temp3 = wt[i];
                wt[i] = wt[j];
                wt[j] = temp3;                 
            }
        }        
    }
    for(int i=0;i<n;i++)
    {
        if(wt[i]<=W)
        {
            place[i] = 1;
            frac[i] = 1.0;
            printf("Selected %d\t",wt[i]);
            profit += pr[i];
            printf("Profit %.2f\n",profit);            
            W -= wt[i];
        }
        else if(wt[i]>W && W!=0)
        {
            place[i] = 1;
            printf("Selected partially %d\t",wt[i]);            
            frac[i] = (float)(wt[i]-W)/wt[i];
            profit += (wt[i]-W)*pw[i];
            printf("Profit %.2f\n",profit);             
            break;
        }
    }
    printf("\n");    
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t",wt[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t",place[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%.2f\t",frac[i]);
    }
    printf("\n");
    printf("Max Profit: %.2f",profit);
}
