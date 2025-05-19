#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int request[MAX_PROCESSES][MAX_RESOURCES];
int num_processes, num_resources;
bool finished[MAX_PROCESSES];

void initialize() {
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter the allocation matrix:\n");
    for(int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for(int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the request matrix:\n");
    for(int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for(int j = 0; j < num_resources; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    printf("Enter the available resources: ");
    for(int i = 0; i < num_resources; i++) {
        scanf("%d", &available[i]);
    }

    for(int i = 0; i < num_processes; i++) {
        finished[i] = false;
    }
}

void detect_deadlock() {
    int work[MAX_RESOURCES];
    int safe_sequence[MAX_PROCESSES];
    int count = 0;
    bool deadlock = false;

    for(int i = 0; i < num_resources; i++) {
        work[i] = available[i];
    }

    bool progress = true;
    while(progress) {
        progress = false;

        for(int i = 0; i < num_processes; i++) {
            if(!finished[i]) {
                bool can_finish = true;

                for(int j = 0; j < num_resources; j++) {
                    if(request[i][j] > work[j]) {
                        can_finish = false;
                        break;
                    }
                }

                if(can_finish) {
                    for(int j = 0; j < num_resources; j++) {
                        work[j] += allocation[i][j];
                    }

                    safe_sequence[count++] = i;
                    finished[i] = true;
                    progress = true;
                }
            }
        }
    }

    deadlock = false;
    for(int i = 0; i < num_processes; i++) {
        if(!finished[i]) {
            deadlock = true;
            break;
        }
    }

    if(deadlock) {
        printf("Deadlock detected!\n");
        printf("Deadlocked processes: ");
        for(int i = 0; i < num_processes; i++) {
            if(!finished[i]) {
                printf("P%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("System is in safe state.\n");
        printf("Safe Sequence is: ");
        for(int i = 0; i < num_processes; i++) {
            printf("P%d ", safe_sequence[i]);
        }
        printf("\n");
    }
}

int main() {
    initialize();
    detect_deadlock();
    return 0;
}
