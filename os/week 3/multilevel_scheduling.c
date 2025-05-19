#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int type;
} Process;

void fcfs(Process queue[], int sys_count, char *queue_name){
    printf("\n%s Processes (FCFS Scheduling):\n", queue_name);
    int time = 0;
    for (int i = 0; i < sys_count; i++){
        printf("Process %d executes from %d to %d\n", queue[i].pid, time, time + queue[i].burst_time);
        time += queue[i].burst_time;
    }
}

int main(){
    int n, sys_count = 0, user_count = 0;
    Process system_queue[MAX_PROCESSES], user_queue[MAX_PROCESSES];
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        Process p;
        printf("Enter process ID, arrival time, burst time, and type (0 for system, 1 for user): \n");
        scanf("%d %d %d %d", &p.pid, &p.arrival_time, &p.burst_time, &p.type);
        if (p.type == 0)
            system_queue[sys_count++] = p;
        else
            user_queue[user_count++] = p;
    }
    fcfs(system_queue, sys_count, "System");
    fcfs(user_queue, user_count, "User");

    return 0;
}

