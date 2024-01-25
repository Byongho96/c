#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int dp[10001];
int bite[101], cost[101];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> bite[i];
	for (int i = 1; i <= N; i++) cin >> cost[i];

    // Fill DP
    int ans = 10000;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 10000; j >= cost[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - cost[i]] + bite[i]);
            if (dp[j] >= M && j < ans) ans = j;
		}
	}

    cout << ans;
    return 0;
}