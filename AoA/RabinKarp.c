#include <stdio.h>
#include <math.h>
#include <string.h>

int main() 
{
    char text[] = "aabbccababbca";
    char pat[] = "bbc";
    int patHash = 0;
    int textHash = 0;
    // Calculate the hash value of the pattern
    for(int i=0;i<strlen(pat);i++)
    {
        patHash = patHash*10 + (int)(pat[i] - 96);
    }
    printf("Pattern Hash: %d\n",patHash);
    
    // Calculate the hash value of the 1st substring of the text
    for(int j=0;j<strlen(pat);j++)
    {
        textHash = textHash*10 + (int)(text[j] - 96);            
    }
    
    printf("Text Hash value: %d\n",textHash);
    
    if(patHash==textHash)
    {
            printf("Pattern found at index 0 of string ");        
    }

    for(int i=1;i<=strlen(text)-strlen(pat);i++)
    {
        // Finding new hash using existing hash
        textHash = (textHash - (int)pow(10,strlen(pat)-1)*(int)(text[i-1]-96))*10 + (int)(text[i+strlen(pat)-1]-96); 
        printf("Text Hash value: %d\n",textHash);
        
        if(patHash==textHash) //Checking if characters are also same
        {
            int flag = 0;
            for(int k=0;k<strlen(pat);k++)
            {
                if(pat[k]!=text[i+k])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
            printf("^ Pattern found at index %d of string\n",i);
            else
            printf("^ Spurious value found at index %d of string\n",i); 
        }
    }
    return 0;
}
