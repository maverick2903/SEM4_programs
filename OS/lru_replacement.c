#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 50
#define MAX_REFERENCES 100

void getData(int *n, int references[], int *nf) {
    printf("Enter length of page reference sequence: ");
    scanf("%d", n);
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < *n; i++)
        scanf("%d", &references[i]);
    printf("Enter no of frames: ");
    scanf("%d", nf);
}

int isHit(int data, int frames[], int nf) {
    for (int i = 0; i < nf; i++) {
        if (frames[i] == data)
            return 1;
    }
    return 0;
}

int getLRU(int ages[], int nf) {
    int lru_index = 0;
    for (int i = 1; i < nf; i++) {
        if (ages[i] < ages[lru_index])
            lru_index = i;
    }
    return lru_index;
}

void lru(int references[], int n, int frames[], int nf) {
    int faults = 0;
    int *ages = (int*) malloc(nf * sizeof(int));
    for (int i = 0; i < nf; i++) {
        frames[i] = -1;
        ages[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        printf("For %d: ", references[i]);
        if (isHit(references[i], frames, nf)) {
            printf("No page fault\n");
            ages[references[i]] = i;
            continue;
        }
        int replace = getLRU(ages, nf);
        frames[replace] = references[i];
        ages[replace] = i;
        faults++;
        printf("Page fault. ");
        printf("Pages in frames: ");
        for (int j = 0; j < nf; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
        }
        printf("\n");
    }
    printf("Total no of page faults: %d\n", faults);
    free(ages);
}

int main() {
    int n, nf, references[MAX_REFERENCES], frames[MAX_FRAMES];
    getData(&n, references, &nf);
    lru(references, n, frames, nf);
    return 0;
}
