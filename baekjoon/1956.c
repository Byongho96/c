#include <stdio.h>

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define fp(a,b,c) for(int a=b; a<=c; a++)

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

int main()
{
    // Get input
	scanf("%d %d", &V, &E);

    // Set initail data
	fp(i, 1, V) {
		fp(j, 1, V) {
			if (i != j) arr[i][j] = INF;
		}
	}

    // Get data
	fp(i, 1, E) {
		scanf("%d %d %d", &a, &b, &c);
		arr[a][b] = c;
	}

	// Run Floyd-Warshall
	floyd();

    int ans = INF;
	fp(i, 1, V) {
		fp(j, 1, V) {
			if (i == j) continue;
			ans = MIN(ans, arr[i][j] + arr[j][i]);
		}
	}
    
    // Print Answer
    printf("%d", ans == INF ? -1 : ans);
	return 0;
}