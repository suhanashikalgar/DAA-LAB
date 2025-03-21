#include <stdio.h>

// Function to solve the 0/1 Knapsack Problem
int knapsack(int values[], int weights[], int W, int n) {
    // Create a 2D array to store the maximum value that can be obtained
    int dp[n + 1][W + 1];
 int i,w;
    // Initialize the dp array
    for ( i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: no items or no capacity
            } else if (weights[i - 1] <= w) {
                // Item can be included
                dp[i][w] = (dp[i - 1][w] > (values[i - 1] + dp[i - 1][w - weights[i - 1]])) ?
                            dp[i - 1][w] :
                            (values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // Item cannot be included
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is in the bottom-right corner of the dp array
    return dp[n][W];
}

int main() {
    int n,i, W;

    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input the maximum weight capacity
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    int values[n], weights[n];

    // Input the values of the items
    printf("Enter the values of the items:\n");
    for ( i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    // Input the weights of the items
    printf("Enter the weights of the items:\n");
    for ( i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    // Call the knapsack function and print the result
    int maxValue = knapsack(values, weights, W, n);
    printf("Maximum value in Knapsack = %d\n", maxValue);

    return 0;
}
