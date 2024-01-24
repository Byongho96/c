#include <iostream>
#include <algorithm>

using namespace std;

#define fp(a,b,c) for(int a=b; a<c+1; a++)
#define fn(a,b,c) for(int a=b; a>c-1; a--)

int dp[1001];
int value[1001];
int l[1001];
int r[1001];
int n, m, i, j;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    // Fill the first line
    fp(j, 1, m) {
        cin >> dp[j];
        dp[j] += dp[j-1];
    }

    // Fill the rest lines
    fp(i, 1, n-1) {
        fp(j, 1, m) cin >> value[j];

        // From left to right
        l[1] = dp[1] + value[1];
        fp(j, 2, m) l[j] = max(dp[j], l[j-1]) + value[j];

        // From right to left
        r[m] = dp[m] + value[m];
        fn(j, m-1, 1) r[j] = max(dp[j], r[j+1]) + value[j];

        // Update DP
        fp(j, 1, m) dp[j] = max(l[j], r[j]);

    }

    cout << dp[m]; 
    return 0;
}