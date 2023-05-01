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

int getOptimal(int references[], int n, int frames[], int nf, int index) {
    int farthest = index, replace = -1;
    for (int i = 0; i < nf; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == references[j])
                break;
        }
        if (j == n)
            return i;
        if (j > farthest) {
            farthest = j;
            replace = i;
        }
    }
    return (replace == -1) ? 0 : replace;
}

void optimal(int references[], int n, int frames[], int nf) {
    int faults = 0;
    for (int i = 0; i < nf; i++)
        frames[i] = -1;
    for (int i = 0; i < n; i++) {
        printf("For %d: ", references[i]);
        if (isHit(references[i], frames, nf)) {
            printf("No page fault\n");
            continue;
        }
        int replace = getOptimal(references, n, frames, nf, i + 1);
        frames[replace] = references[i];
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
}

int main() {
    int n, nf, references[MAX_REFERENCES], frames[MAX_FRAMES];
    getData(&n, references, &nf);
    optimal(references, n, frames, nf);
    return 0;
}
