#include<stdio.h>
#include<stdlib.h>
#include<time.h>
float s,e,t,s2,e2,t2,s3,e3,t3;
void merge(int a[],int beg,int mid,int end)
{
    int i,j,k,temp[50000],index;
    i=beg;
    j=mid+1;
    index=beg;
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            temp[index]=a[i];
            i++;
        }
        else
        {
            temp[index]=a[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]=a[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=a[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
    a[k]=temp[k];
}
void mergesort(int a[],int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}
void main()
{
    int i,a[50000],b[50000],c[50000],n;
    printf("enter the value of n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=i;
    }
    s=clock();
    mergesort(a,0,n-1);
    e=clock();
    t=(float)(e-s);
    printf("\nBEST CASE:%f",t);
    for(i=0;i<n;i++)
    {
        b[i]=rand();
    }
    s2=clock();
    mergesort(b,0,n-1);
    e2=clock();
    t2=(float)(e2-s2);
    printf("\nAVERAGE CASE:%f",t2);
    for(i=0;i<n;i++)
    {
        c[i]=i;
    }
    s3=clock();
    mergesort(c,0,n-1);
    e3=clock();
    t3=(float)(e3-s3);
    printf("\nWORST CASE:%f",t3);
    
}
