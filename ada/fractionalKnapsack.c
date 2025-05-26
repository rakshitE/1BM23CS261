#include <stdio.h>

void knapsack(int n, int p[], int w[], int W) {
    int used[n];  // Array to track if an item has been added or partially added
    for (int i = 0; i < n; ++i) {
        used[i] = 0;
    }

    int cur_w = W;  // Current available weight in the bag
    float tot_v = 0.0;  // Total value of items in the bag
    int i, maxi;

    // Loop to fill the knapsack
    while (cur_w > 0) {
        maxi = -1;

        // Find the next best item (highest value-to-weight ratio)
        for (i = 0; i < n; ++i) {
            if ((used[i] == 0) &&
                ((maxi == -1) || ((float)p[i] / w[i] > (float)p[maxi] / w[maxi]))) {
                maxi = i;
            }
        }

        used[maxi] = 1;  // Mark the item as used

        // If the item can fit completely in the bag
        if (w[maxi] <= cur_w) {
            cur_w -= w[maxi];
            tot_v += p[maxi];
            printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n",k 
                   maxi + 1, w[maxi], p[maxi], cur_w);
        } else {
            // If only a fraction of the item can fit in the bag
            int taken = cur_w;
            cur_w = 0;
            tot_v += (float)taken / w[maxi] * p[maxi];
            printf("Added %d%% (%d, %d) of object %d in the bag.\n",
                   (int)((float)taken / w[maxi] * 100), w[maxi], p[maxi], maxi + 1);
        }

        // If the knapsack is full, stop the loop
        if (cur_w == 0) {
            break;
        }
    }

    printf("Filled the bag with objects worth %.2f.\n", tot_v);
}

int main() {
    int n, W;

    // Input the number of objects
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    int p[n], w[n];

    // Input the profits of the objects
    printf("Enter the profits of the objects: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // Input the weights of the objects
    printf("Enter the weights of the objects: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    // Input the maximum weight capacity of the bag
    printf("Enter the maximum weight of the bag: ");
    scanf("%d", &W);

    // Call knapsack function to solve the problem
    knapsack(n, p, w, W);

    return 0;
}

OUTPUT :
Enter the number of objects: 7
Enter the profits of the objects: 5 10 15 7 8 9 4
Enter the weights of the objects: 1 3 5 4 1 3 2
Enter the maximum weight of the bag: 15
Added object 5 (1, 8) completely in the bag. Space left: 14.
Added object 1 (1, 5) completely in the bag. Space left: 13.
Added object 2 (3, 10) completely in the bag. Space left: 10.
Added object 3 (5, 15) completely in the bag. Space left: 5.
Added object 6 (3, 9) completely in the bag. Space left: 2.
Added object 7 (2, 4) completely in the bag. Space left: 0.
Filled the bag with objects worth 51.00.
