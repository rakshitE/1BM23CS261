#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int pid;
    int bt;
    int period;
    int deadline;
    int remaining_time;
    int next_release;
} Task;

int lcm(int a, int b);
void rms(Task tasks[], int n, int hyper_period);
void edf(Task tasks[], int n, int hyper_period);

int main(){
    int n, choice;
    printf("Enter no of tasks: \n");
    scanf("%d", &n);
    Task p[n];
    printf("\nChoose Scheduling type: \n");
    printf("1. Rate Monotonic\n");
    printf("2. Earliest Deadline First\n");
    scanf("%d", &choice);
    int hyper_period = 1;

    switch(choice){
    case 1:
        double worst = n * (pow(2.0, 1.0 / n) - 1.0);
        printf("Enter task details(ID, BT, Period):\n");
        for (int i = 0; i < n; i++){
            scanf("%d %d %d", &p[i].pid, &p[i].bt, &p[i].period);
            hyper_period = lcm(hyper_period, p[i].period);
        }
        rms(p, n, hyper_period);
        break;
    case 2:
        printf("Enter task details(ID, BT, Deadlines, Period):\n");
        for (int i = 0; i < n; i++){
            scanf("%d %d %d %d", &p[i].pid, &p[i].bt, &p[i].deadline, &p[i].period);
            hyper_period = lcm(hyper_period, p[i].period);
        }
        edf(p, n, hyper_period);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}

int lcm(int a, int b){
    int temp_a = a, temp_b = b;
    while (temp_b != 0) {
        int temp = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = temp;
    }
    return (a * b) / temp_a;
}

void rms(Task tasks[], int n, int hyper_period){
    double worst = n * (pow(2.0, 1.0 / n) - 1);
    double prob = 0;
    for (int i = 0; i < n; i++)
        prob += (double) tasks[i].bt / tasks[i].period;
    printf("Rate Monotone Scheduling:\n");
    printf("PID\t\t\tBurst\t\t\tPeriod\n");
    for (int i = 0; i < n; i++){
        printf("%d\t\t\t %d\t\t\t %d\n", tasks[i].pid, tasks[i].bt, tasks[i].period);
    }
    printf("LCM = %d\n", hyper_period);
    if (worst <= prob){
        printf("%f <= %f => false", prob, worst);
        return;
    }
    printf("%f < %f", worst, prob);
    for (int time = 0; time < hyper_period; time++) {
        int min_period = 1e9, current = -1;

        for (int i = 0; i < n; i++) {
            if (time == tasks[i].next_release)
                tasks[i].remaining_time = tasks[i].bt;

            if (tasks[i].remaining_time > 0 && tasks[i].period < min_period) {
                min_period = tasks[i].period;
                current = i;
            }
        }

        if (current != -1) {
            printf("Time %2d: Task %d running\n", time, tasks[current].pid);
            tasks[current].remaining_time--;
            if (tasks[current].remaining_time == 0)
                tasks[current].next_release += tasks[current].period;
        } else {
            printf("Time %2d: Idle\n", time);
        }
    }
}

void edf(Task tasks[], int n, int hyper_period){
    printf("Earliest Deadline first:\n");
    printf("PID\t\t\tBurst\t\t\tDeadline");
    for (int i = 0; i < n; i++){
        printf("%d\t\t\t %d\t\t\t %d\n", tasks[i].pid, tasks[i].bt, tasks[i].deadline);
    }
    printf("Scheduling occurs for %d ms\n", &hyper_period);

    for (int time = 0; time < hyper_period; time++) {
        int earliest_deadline = 1e9, current = -1;

        for (int i = 0; i < n; i++) {
            if (time == tasks[i].next_release)
                tasks[i].remaining_time = tasks[i].bt;

            if (tasks[i].remaining_time > 0) {
                int deadline = tasks[i].next_release + tasks[i].deadline;
                if (deadline < earliest_deadline) {
                    earliest_deadline = deadline;
                    current = i;
                }
            }
        }

        if (current != -1) {
            printf("Time %2d: Task %d running\n", time, tasks[current].pid);
            tasks[current].remaining_time--;
            if (tasks[current].remaining_time == 0)
                tasks[current].next_release += tasks[current].period;
        } else {
            printf("Time %2d: Idle\n", time);
        }
    }
}
