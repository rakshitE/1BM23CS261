#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int num_processes, num_resources;

// Function to initialize the data structures
void initialize() {
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter available resources:\n");
    for(int i = 0; i < num_resources; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter maximum resources for each process:\n");
    for(int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for(int j = 0; j < num_resources; j++) {
            scanf("%d", &maximum[i][j]);
            need[i][j] = maximum[i][j];
        }
    }

    printf("Enter allocated resources for each process:\n");
    for(int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for(int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] -= allocation[i][j];
            available[j] -= allocation[i][j];
        }
    }
}

// Function to check if the system is in a safe state
bool is_safe() {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};
    int safe_sequence[MAX_PROCESSES];
    int count = 0;

    // Initialize work array
    for(int i = 0; i < num_resources; i++) {
        work[i] = available[i];
    }

    while(count < num_processes) {
        bool found = false;

        for(int i = 0; i < num_processes; i++) {
            if(!finish[i]) {
                bool can_allocate = true;

                for(int j = 0; j < num_resources; j++) {
                    if(need[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }

                if(can_allocate) {
                    for(int j = 0; j < num_resources; j++) {
                        work[j] += allocation[i][j];
                    }

                    safe_sequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if(!found) {
            printf("System is not in safe state!\n");
            return false;
        }
    }

    printf("System is in safe state.\nSafe sequence: ");
    for(int i = 0; i < num_processes; i++) {
        printf("P%d ", safe_sequence[i]);
    }
    printf("\n");
    return true;
}

// Main function
int main() {
    initialize();
    printf("\nAllocation matrix:\n");
    for(int i = 0; i < num_processes; i++) {
        for(int j = 0; j < num_resources; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum matrix:\n");
    for (int i = 0; i < num_processes; i++){
        for(int j = 0; j < num_resources; j++){
            printf("%d ", maximum[i][j]);
        }
        printf("\n");
    }

    printf("\nNeed matrix:\n");
    for(int i = 0; i < num_processes; i++) {
        for(int j = 0; j < num_resources; j++) {
            printf("%d ", need[i][j]);
        }
            printf("\n");
    }

     if(!is_safe()) {
        printf("Initial state is not safe. Exiting...\n");
        return 1;
     }

    return 0;
}
