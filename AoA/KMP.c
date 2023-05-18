#include<stdio.h>
#include<string.h>
int pi[100];
void prefix_fun(char p[])
{
    int k=0;
    pi[0]=0;
    for(int i=1; i<strlen(p);i++)
    {
        while(k>0 && p[k]!=p[i])
        k=pi[k];
        if(p[k]==p[i])
        k++;
        pi[i]=k;
    }
}
void main()
{
    int tlen,plen,q=0;
    char text[200]="ababcabcabababd",pat[100]="abc";
    tlen = strlen(text);
    plen = strlen(pat);
    prefix_fun(pat);
    for(int i=0;i<tlen;i++)
    {
        while(q>0 && pat[q]!=text[i])
        q=pi[q-1];
        if(pat[q]==text[i])
        q++;
        if(q==plen)
        printf("pattern occurs at %d\n",i-plen+1);
    }
}
