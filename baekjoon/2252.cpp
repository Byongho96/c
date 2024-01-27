#include <iostream>
#include <vector>

using namespace std;

#define fp(a,b,c) for(int a=b; a<c+1; a++)

typedef vector<short> vs;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int M, i;
    short N, cur, a, b;
    int degree[32001] = {0,};
    vs graph[32001];
    vs queue, ans;

    cin >> N >> M;

    // Initiate data
    fp(i, 1, M) {
        cin >> a >> b;
        graph[a].push_back(b);
        degree[b]++;
    }

    // Set the starts
    fp(i, 1, N) {
        if (degree[i] == 0) queue.push_back(i);
    }

    // Topological sort
    fp(i, 0, N-1) {
        cur = queue[i];
        ans.push_back(cur);
        for (short j : graph[cur] ) {
            degree[j]--;
            if (degree[j] == 0) queue.push_back(j);
        }
    }

    // Print answer
    fp(i, 0, N -1) {
        cout << ans[i] << ' ';
    }
    return 0;
}