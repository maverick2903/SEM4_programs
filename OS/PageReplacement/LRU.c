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

int getLRU(int references[], int n, int frames[], int nf, int index) 
{
    int least = index, replace = -1;
    for (int i = 0; i < nf; i++) 
    {
        int j;
        for (j = index; j > 0; j--) 
        {
            if (frames[i] == references[j])
                break;
        }
        if (j == 0)
            return i;
        if (j < least) 
        {
            least = j;
            replace = i;
        }
    }
    return (replace == -1) ? 0 : replace;
}

void LRU(int references[], int n, int frames[], int nf) 
{
    int faults = 0;
    int hits = 0;
    for (int i = 0; i < nf; i++)
        frames[i] = -1;
        
    int frame_index = 0;
    for (int i = 0; i < n; i++) 
    {
        printf("For %d: ", references[i]);
        if (isHit(references[i], frames, nf)) 
        {
            printf("No page fault\n");
            continue;
        }
        if(frame_index<nf)
        {
            frames[frame_index] = references[i];
            frame_index++;
        }
        else
        {        
            int replace = getLRU(references, n, frames, nf, i - 1);
            frames[replace] = references[i];
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
    LRU(references, n, frames, nf);
    return 0;
}
