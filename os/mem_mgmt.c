#include <stdio.h>
#include <stdlib.h>

void firstFit(int blockSize[], int m, int fileSize[], int n);
void bestFit(int blockSize[], int m, int fileSize[], int n);
void worstFit(int blockSize[], int m, int fileSize[], int n);

int main() {
    int m, n, choice;

    printf("Memory Management Scheme\n");

    printf("Enter the number of blocks: ");
    scanf("%d", &m);
    int blockSize[m];

    printf("Enter the number of files: ");
    scanf("%d", &n);
    int fileSize[n];

    printf("\nEnter the size of the blocks:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the size of the files:\n");
    for (int i = 0; i < n; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &fileSize[i]);
    }

    while (1) {
        printf("\n1. First Fit\n");
        printf("2. Best Fit\n");
        printf("3. Worst Fit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMemory Management Scheme - First Fit\n");
                printf("File_No:\tFile_size:\tBlock_no:\tBlock_size:\n");
                firstFit(blockSize, m, fileSize, n);
                break;
            case 2:
                printf("\nMemory Management Scheme - Best Fit\n");
                printf("File_No:\tFile_size:\tBlock_no:\tBlock_size:\n");
                bestFit(blockSize, m, fileSize, n);
                break;
            case 3:
                printf("\nMemory Management Scheme - Worst Fit\n");
                printf("File_No:\tFile_size:\tBlock_no:\tBlock_size:\n");
                worstFit(blockSize, m, fileSize, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void firstFit(int blockSize[], int m, int fileSize[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= fileSize[i]) {
                allocation[i] = j;
                blockSize[j] -= fileSize[i];
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, fileSize[i],
                   allocation[i] + 1, blockSize[allocation[i]] + fileSize[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\t-\n", i + 1, fileSize[i]);
        }
    }
}

void bestFit(int blockSize[], int m, int fileSize[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= fileSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= fileSize[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, fileSize[i],
                   allocation[i] + 1, blockSize[allocation[i]] + fileSize[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\t-\n", i + 1, fileSize[i]);
        }
    }
}

void worstFit(int blockSize[], int m, int fileSize[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= fileSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= fileSize[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, fileSize[i],
                   allocation[i] + 1, blockSize[allocation[i]] + fileSize[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\t-\n", i + 1, fileSize[i]);
        }
    }
}
