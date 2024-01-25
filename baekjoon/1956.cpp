#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define fp(a,b,c) for(int a=b; a<c+1; a++)

int V, E, a, b, c;
int arr[401][401];
int INF = 1e9;

// Floyd-Warshall
void floyd() {
	fp(m, 1, V) {
		fp(i, 1, V) {
			fp(j, 1, V) {
				if (arr[i][j] > arr[i][m] + arr[m][j]) {
					arr[i][j] = arr[i][m] + arr[m][j];
				}
			}
		}
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

	int ans = INF;

	cin >> V >> E;

  	// Set initail data
	fp(i, 1, V) {
		fp(j, 1, V) {
			if (i != j) arr[i][j] = INF;
		}
	}

    // Get data
	fp(i, 1, E) {
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

    // Run Floyd-Warshall
	floyd();

	fp(i, 1, V) {
		fp(j, 1, V) {
			if (i == j) continue;
			ans = min(ans, arr[i][j] + arr[j][i]);
		}
	}
    
	cout << (ans == INF ? -1 : ans);
}