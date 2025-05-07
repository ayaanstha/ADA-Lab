#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack_01(int n, int W, int wt[], int val[]) {
    int dp[MAX_ITEMS][MAX_CAPACITY];

    // Initialize base cases
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Print DP Table
    printf("\nDP Table:\n");
    printf("        ");
    for (int w = 0; w <= W; w++)
        printf("%3d ", w);
    printf("\n");

    for (int i = 0; i <= n; i++) {
        if (i == 0)
            printf("i=%d     ", i);
        else
            printf("w%d=%d,v%d=%d ", i, wt[i - 1], i, val[i - 1]);

        for (int w = 0; w <= W; w++)
            printf("%3d ", dp[i][w]);
        printf("\n");
    }

    return dp[n][W];
}

int main() {
    int n, W;
    int wt[MAX_ITEMS], val[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &wt[i], &val[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int max_value = knapsack_01(n, W, wt, val);
    printf("\nMaximum value in knapsack: %d\n", max_value);

    return 0;
}
