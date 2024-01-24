#include <stdio.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int dp[1001],value[1001],l[1001],r[1001];


int main()
{
	int n, m, i, j;
	scanf("%d %d", &n, &m);

    // Fill first line dp
	for(j = 1; j < m + 1; j++)
	{
		scanf("%d", dp+j);
		dp[j] += dp[j-1];
	}

    // Fill the rest lines
	for(i = 1; i < n; i++)
	{
		for(j = 1; j < m + 1; j++) scanf("%d", value+j);
		
        // Fill from left to right
		l[1] = dp[1] + value[1];
		for(j = 2; j < m + 1; j++) l[j] = MAX(dp[j], l[j-1]) + value[j];

        // Fill from right to left
		r[m] = dp[m] + value[m];
		for(j = m - 1; j > 0; j--) r[j] = MAX(dp[j], r[j+1]) + value[j];
		
        // Update dp
		for(j = 1; j < m + 1; j++) dp[j] = MAX(l[j], r[j]);
	}

	printf("%d", dp[m]);
	return 0;
}