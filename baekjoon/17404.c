#include <stdio.h>

#define INF 1000001;
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))


int main() {
    int N, i, j, cur, prev, ans;
    int RGB[1000][3], DP[2][3];

    // Get input
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        for(j = 0; j < 3; j++) scanf("%d", &RGB[i][j]);
    }

    // Fill DP
    for(i = 0; i < 3; i++) {
        // Set the start color
        DP[0][0] = INF;
        DP[0][1] = INF;
        DP[0][2] = INF;
        DP[0][i] = RGB[0][i];

        for(j = 1; j < N; j++)  {
            cur = j % 2;
            prev = 1 - cur;
            DP[cur][0] = RGB[j][0] + MIN(DP[prev][1], DP[prev][2]);
            DP[cur][1] = RGB[j][1] + MIN(DP[prev][0], DP[prev][2]);
            DP[cur][2] = RGB[j][2] + MIN(DP[prev][0], DP[prev][1]);
        }

        // Update answer
        ans = MIN(ans, MIN(DP[cur][(i + 1) % 3], DP[cur][(i + 2) % 3]));
    }
    printf("%d", ans);
}