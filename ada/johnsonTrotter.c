#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

// Structure to represent each element and its direction
typedef struct {
    int value;
    int dir;
} Element;

// Function to print the current permutation
void printPermutation(Element *perm, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i].value);
    }
    printf("\n");
}

// Function to find the largest mobile element
int getMobile(Element *perm, int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++) {
        int nextIndex = i + perm[i].dir;
        if (nextIndex >= 0 && nextIndex < n) {
            if (perm[i].value > perm[nextIndex].value) {
                if (perm[i].value > mobile) {
                    mobile = perm[i].value;
                    mobileIndex = i;
                }
            }
        }
    }

    return mobileIndex;
}

// Function to reverse directions of elements greater than the given value
void reverseDirections(Element *perm, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (perm[i].value > value) {
            perm[i].dir = -perm[i].dir;
        }
    }
}

int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

int main() {
    int n;

    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    Element *perm = malloc(n * sizeof(Element));

    // Initialize the permutation
    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1;
        perm[i].dir = LEFT;
    }

    int total = factorial(n);
    for (int i = 0; i < total; i++) {
        printPermutation(perm, n);

        int mobileIndex = getMobile(perm, n);
        if (mobileIndex == -1) break;

        int swapIndex = mobileIndex + perm[mobileIndex].dir;

        // Swap the mobile element with the adjacent one
        Element temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        // Update directions
        reverseDirections(perm, n, perm[swapIndex].value);
    }

    free(perm);
    return 0;
}
