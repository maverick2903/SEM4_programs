#include <stdio.h>
#define MAX_FRAMES 50
#define MAX_REFERENCES 100

void getData(int *n, int references[], int *nf) {
    printf("Enter length of page reference sequence:");
    scanf("%d", n);
    printf("Enter the page reference sequence:");
    for (int i = 0; i < *n; i++)
        scanf("%d", &references[i]);
    printf("Enter no of frames:");
    scanf("%d", nf);
}

int isHit(int data, int frames[], int nf) {
    for (int i = 0; i < nf; i++) {
        if (frames[i] == data)
            return i;
    }
    return -1;
}

int getLFU(int references[], int freq[], int nf) 
{
    int min = 999, replace = -1;
    for (int i = 0; i < nf; i++) 
    {
        if (freq[i] < min) 
        {
            min = freq[i];
            replace = i;
        }
    }
    return (replace == -1) ? 0 : replace;
}

void LFU(int references[], int n, int frames[], int nf) 
{
    int faults = 0;
    int hits = 0;
    int freq[nf];
    int frame_index = 0;    
    for (int i = 0; i < nf; i++)
    {
        frames[i] = -1;
        freq[i] = 0;        
    }
    for (int i = 0; i < n; i++) 
    {
        printf("For %d: ", references[i]);
        int hitIndex = isHit(references[i], frames, nf);
        if (hitIndex!=-1) 
        {
            printf("No page fault\n");
            freq[hitIndex]++;
            continue;
        }
        if(frame_index<nf)
        {
            frames[frame_index] = references[i];
            freq[frame_index]++;
            frame_index++;
        }
        else
        {        
            int replace = getLFU(references,freq, nf);
            frames[replace] = references[i];
            int prevCount=0;
            for (int j = 0; j <=i; j++)
            {
                if(references[j]==references[i])
                {
                    prevCount++;
                }
            }
            freq[replace] = prevCount;
        }
        printf("Page fault. ");
        printf("Pages in frames: ");
        for (int j = 0; j < nf; j++) 
        {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
        }
        printf("\n");
        faults++;        
    }
    printf("Total no of page faults: %d\n", faults);
    hits = n - faults;    
    printf("Total no of page hits: %d\n", hits);
    float hit_ratio = 100.0 * ((float)hits / (float)n);
    float miss_ratio = 100.0 - hit_ratio;     
    printf("Hit Ratio: %f\n", hit_ratio);    
    printf("Miss Ratio: %f\n", miss_ratio);     
}

int main() 
{
    int n, nf, references[MAX_REFERENCES], frames[MAX_FRAMES];
    getData(&n, references, &nf);
    LFU(references, n, frames, nf);
    return 0;
}
