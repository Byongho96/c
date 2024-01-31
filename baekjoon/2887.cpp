#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pii pair<int, int>

struct Edge {
    int weight;
    int node1;
    int node2;
};

bool Compare(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

int find_set(int par[], int x) {
    while (par[x] != x) x = par[x];
	return x;
}

void union_by_rank(int par[], int rank[], int x, int y) {
    if (rank[x] > rank[y]) par[x] = y;
    else if (rank[x] < rank[y]) par[y] = x;
    else par[x] = y; rank[x]++; 
}

int kruskal(int N, vector<Edge> &edge) {
    // create rank and parent array
    int* rank = new int[N];
    int* par = new int[N];
    for (int i = 0; i < N; i++) {
        par[i] = i;
    }

    // kruskal algorithm
    int mst = 1;
    int weight = 0;
    int N1, N2;
    for (int i = 0; i < 3 * (N - 1); i++) {
        N1 = find_set(par, edge[i].node1);
        N2 = find_set(par, edge[i].node2);
		if (N1 != N2) {
            // union node
			union_by_rank(par, rank, N1, N2);
            mst += 1;
			weight += edge[i].weight;
		}
        // early end condition
        if (mst == N) break;
	}

    // release dynamic array
    delete[] par;
    delete[] rank;

    // return the result
    return weight;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // get input
    int N;
    cin >> N;

    vector<pii> X, Y, Z;
    int x, y, z;
    for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });
	}

    // sort each axis
    sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

    // make available edge list
    vector<Edge> edge;
    for (int i = 1; i < N; i++) {
		edge.push_back({ X[i].first - X[i - 1].first , X[i].second, X[i - 1].second });
		edge.push_back({ Y[i].first - Y[i - 1].first , Y[i].second, Y[i - 1].second });
		edge.push_back({ Z[i].first - Z[i - 1].first , Z[i].second, Z[i - 1].second });
	}
    sort(edge.begin(), edge.end(), Compare);

    // print answer
    cout << kruskal(N, edge);
    return 0;
}