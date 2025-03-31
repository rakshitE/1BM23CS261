#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int no;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} Process;

void fcfs(Process processes[], int n);
void sjf(Process processes[], int n);

void sortByArrivalTime(Process processes[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (processes[j].at > processes[j+1].at) {
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}


int main() {
    int n;
    printf("Enter no of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Arrival time for P%d: ", i + 1);
        scanf("%d", &processes[i].at);
        processes[i].no = i + 1;
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &processes[i].bt);
    }

    fcfs(processes, n);
    sjf(processes, n);

    return 0;
}

void fcfs(Process processes[], int n) {
    sortByArrivalTime(processes, n);
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < processes[i].at) {
            time = processes[i].at;
        }
        processes[i].ct = time + processes[i].bt;
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
        time = processes[i].ct;
    }

    printf("\nFCFS Scheduling:\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].no, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
    }
}

void sjf(Process processes[], int n) {
    int time = 0;
    int completed = 0;
    int shortest;
    while (completed != n) {
        shortest = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].at <= time && processes[i].bt > 0) {
                if (shortest == -1 || processes[i].bt < processes[shortest].bt) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        processes[shortest].ct = time + processes[shortest].bt;
        processes[shortest].tat = processes[shortest].ct - processes[shortest].at;
        processes[shortest].wt = processes[shortest].tat - processes[shortest].bt;
        time = processes[shortest].ct;
        processes[shortest].bt = 0;
        completed++;
    }

    printf("\nSJF Scheduling:\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].no, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
    }
}
