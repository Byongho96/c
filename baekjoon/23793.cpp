#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000001

using namespace std;

struct Edge {
    int weight;
    int node;
};

// Min heap operation
struct cmp {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};


// Dijkstra algorithm
int dijkstra(int N, vector<vector<Edge>>& adjLst, int start, int end, int middle = 0) {
    vector<int> distance(N + 1, INF); 
    priority_queue<Edge, vector<Edge>, cmp> heap; 

    // Set the start
    distance[start] = 0;
    heap.push({0, start});

    while (!heap.empty()) {
        Edge curNode = heap.top();
        heap.pop();

        // Filter invalid condition
        if (distance[curNode.node] < curNode.weight) {
            continue;
        }

        // End condition
        if (curNode.node == end) {
            return curNode.weight;
        }

        // Traverse adjacent nodes
        for (const Edge& neighbor : adjLst[curNode.node]) {

            // Disabled node
            if (middle && neighbor.node == middle) {
                continue;
            }

            if (curNode.weight + neighbor.weight < distance[neighbor.node]) {
                distance[neighbor.node] = curNode.weight + neighbor.weight;
                heap.push({curNode.weight + neighbor.weight, neighbor.node});
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    vector<vector<Edge>> adjLst(100001);
    int X, Y, Z;

    // Get inputs
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adjLst[a].push_back({w, b});
    }
    cin >> X >> Y >> Z;

    // Pass through Y
    int x_to_y = dijkstra(N, adjLst, X, Y);
    int y_to_z = -1;
    if (x_to_y > 0) {
        y_to_z = dijkstra(N, adjLst, Y, Z);
    }

    // Don't pass through Y
    int x_to_z = dijkstra(N, adjLst, X, Z, Y);

    // Console out answers
    if(y_to_z > 0) cout << x_to_y + y_to_z <<" ";
    else cout << -1 <<" ";
    cout<< x_to_z <<" ";

    return 0;
}
