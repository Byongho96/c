#include <stdio.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int main()
{
	int N, M, i, j;
    int dp[10001]={0,}, memo[101], cost[101];

    // Get input
	scanf("%d %d", &N, &M);
	for(i = 1; i <= N; i++) scanf("%d", memo+i);
    for(i = 1; i <= N; i++) scanf("%d", cost+i);

    // Fill DP
    int ans = 10001;
	for(i = 1; i <= N; i++) 
        for(j = ans-1; j >= cost[i]; j--)  {
            dp[j] = MAX(dp[j], dp[j - cost[i]] + memo[i]);
            if (dp[j] >= M) ans = j;
        }
    
    // Print Answer
    printf("%d", ans);
	return 0;
}