#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000001;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int N, i, j, cur, prev, ans;
    int DP[2][3], RGB[1000][3];

    // Get input    
    cin >> N;
    for(i = 0 ; i < N; i++) {
        for(j = 0 ; j < 3; j++) cin >> RGB[i][j];
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
            DP[cur][0] = RGB[j][0] + min(DP[prev][1], DP[prev][2]);
            DP[cur][1] = RGB[j][1] + min(DP[prev][0], DP[prev][2]);
            DP[cur][2] = RGB[j][2] + min(DP[prev][0], DP[prev][1]);
        }

        // Update answer
        ans = min(ans, min(DP[cur][(i + 1) % 3], DP[cur][(i + 2) % 3]));
    }
    
    cout << ans;
}   