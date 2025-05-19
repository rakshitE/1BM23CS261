#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    int arrival;
    int burst;
    int priority;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
    int started;
} Process;

void priorityNonPreemptive(Process p[], int n);
void priorityPreemptive(Process p[], int n);
void sortByArrival(Process p[], int n);
void printProcesses(Process p[], int n);

int main() {
    int n, choice;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details (ID, Arrival Time, Burst Time, Priority):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &p[i].id, &p[i].arrival, &p[i].burst, &p[i].priority);
        p[i].remaining = p[i].burst;
        p[i].started = 0;
    }

    printf("\nChoose Scheduling Type:\n1. Non-Preemptive Priority\n2. Preemptive Priority\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        priorityNonPreemptive(p, n);
    } else if (choice == 2) {
        priorityPreemptive(p, n);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

void priorityNonPreemptive(Process p[], int n) {
    sortByArrival(p, n);
    int completed = 0, currentTime = 0;

    while (completed < n) {
        int idx = -1, highestPriority = 10000;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= currentTime && p[i].completion == 0) {
                if (p[i].priority < highestPriority) {
                    highestPriority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            currentTime += p[idx].burst;
            p[idx].completion = currentTime;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            completed++;
        } else {
            currentTime++;
        }
    }

    printf("\nNon-Preemptive Priority Scheduling:\n");
    printProcesses(p, n);
}

void priorityPreemptive(Process p[], int n) {
    sortByArrival(p, n);
    int completed = 0, currentTime = 0;

    while (completed < n) {
        int idx = -1, highestPriority = 10000;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= currentTime && p[i].remaining > 0) {
                if (p[i].priority < highestPriority) {
                    highestPriority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].remaining--;
            if (p[idx].remaining == 0) {
                p[idx].completion = currentTime + 1;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
                completed++;
            }
        }
        currentTime++;
    }

    printf("\nPreemptive Priority Scheduling:\n");
    printProcesses(p, n);
}

void sortByArrival(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void printProcesses(Process p[], int n) {
    printf("\nID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].id, p[i].arrival, p[i].burst, p[i].priority,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }
}
