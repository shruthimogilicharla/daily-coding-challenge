#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int cost[100], dp[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &cost[i]);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i < n; i++) {
        if(dp[i-1] < dp[i-2])
            dp[i] = cost[i] + dp[i-1];
        else
            dp[i] = cost[i] + dp[i-2];
    }

    if(dp[n-1] < dp[n-2])
        printf("%d", dp[n-1]);
    else
        printf("%d", dp[n-2]);

    return 0;
}
