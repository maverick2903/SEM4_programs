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
            return 1;
    }
    return 0;
}

int getFIFO(int references[], int frame_count[], int nf) 
{
    int max_count = 0, replace = -1;
    for (int i = 0; i < nf; i++) 
    {
        if (frame_count[i] > max_count) 
        {
            max_count = frame_count[i];
            replace = i;
        }
    }
    return (replace == -1) ? 0 : replace;
}

void FIFO(int references[], int n, int frames[], int nf) 
{
    int faults = 0;
    int hits = 0;
    int frame_count[nf];
    for (int i = 0; i < nf; i++)
    {
        frames[i] = -1;
        frame_count[i] = 0;        
    }
        
    int frame_index = 0;
    for (int i = 0; i < n; i++) 
    {
        printf("For %d: ", references[i]);
        if (isHit(references[i], frames, nf)) 
        {
            printf("No page fault\n");
            for (int i = 0; i <=frame_index; i++)
            {
                frame_count[i]++;        
            }
            continue;
        }
        if(frame_index<nf)
        {
            frames[frame_index] = references[i];
            for (int i = 0; i <=frame_index; i++)
            {
                frame_count[i]++;        
            }
            frame_index++;
        }
        else
        {        
            int replace = getFIFO(references,frame_count, nf);
            frames[replace] = references[i];
            for (int i = 0; i <=frame_index; i++)
            {
                frame_count[i]++;        
            }  
            frame_count[replace] = 1;
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
    FIFO(references, n, frames, nf);
    return 0;
}
