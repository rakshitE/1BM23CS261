#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int W, int weight[], int value[], int n) {
    int dp[n + 1][W + 1];

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W]; // Maximum value that can be put in the knapsack
}

// Main function
int main() {
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(value) / sizeof(value[0]);

    int maxValue = knapsack(W, weight, value, n);
    printf("Maximum value in Knapsack = %d\n", maxValue);

    return 0;
}
