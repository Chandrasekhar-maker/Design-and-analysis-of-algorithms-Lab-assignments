//NAME: SHAIK LAL JOHN BASHA REGNO:AP25110010596
#include <stdio.h>

#define N 4
#define CAPACITY 8

int main() {
    int profit[N] = {1, 2, 5, 6};
    int weight[N] = {2, 3, 4, 5};

    int dp[N + 1][CAPACITY + 1];

    int i, w;

    for (i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }

    for (w = 0; w <= CAPACITY; w++) {
        dp[0][w] = 0;
    }

    for (i = 1; i <= N; i++) {
        for (w = 1; w <= CAPACITY; w++) {

            if (weight[i - 1] <= w) {
                int include = profit[i - 1] +
                              dp[i - 1][w - weight[i - 1]];

                int exclude = dp[i - 1][w];

                if (include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("DP Table:\n\n");

    for (i = 0; i <= N; i++) {
        for (w = 0; w <= CAPACITY; w++) {
            printf("%d\t", dp[i][w]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", dp[N][CAPACITY]);

    int selected[N];
    int count = 0;
    int remainingCapacity = CAPACITY;
    int totalWeight = 0;

    for (i = N; i > 0; i--) {

        if (dp[i][remainingCapacity] !=
            dp[i - 1][remainingCapacity]) {

            selected[count] = i;
            count++;

            totalWeight += weight[i - 1];

            remainingCapacity -= weight[i - 1];
        }
    }
    printf("Selected Items: ");

    for (i = count - 1; i >= 0; i--) {
        printf("Item %d ", selected[i]);
    }

    printf("\nTotal Weight = %d\n", totalWeight);

    return 0;
}
