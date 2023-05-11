#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};

void swap(struct process *a, struct process *b) {
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_processes(struct process p[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].burst_time > p[j].burst_time) {
                swap(&p[i], &p[j]);
            }
        }
    }
}

void calculate_waiting_time(struct process p[], int n) {
    p[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    }
}

void calculate_turnaround_time(struct process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

void print_gantt_chart(struct process p[], int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("  %d  ", p[i].pid);
    }
    printf("\n");
    printf("0");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].burst_time; j++) {
            printf("--");
        }
        printf("%d", p[i].turnaround_time);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i+1;
        p[i].remaining_time = p[i].burst_time;
    }
    sort_processes(p, n);
    calculate_waiting_time(p, n);
    calculate_turnaround_time(p, n);
    print_gantt_chart(p, n);
    return 0;
}
