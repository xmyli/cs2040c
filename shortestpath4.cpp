#include <iostream>
#include <climits>
#include <tuple>
#include <vector>

using namespace std;

int getMinPath(int src, int dest, int limit, vector<tuple<int, int, int> >& edges, int numVertices) {
    vector<vector<int> > DP(numVertices, vector<int>(limit+1, INT_MAX));

    DP[src][1] = 0;

    int minOfDest = INT_MAX;

    for (size_t k = 1; k <= limit; k++) {
        vector<tuple<int, int, int> >::iterator itr;
        for (itr = edges.begin(); itr != edges.end(); itr++) {
            int p = get<0>(*itr);
            int u = get<1>(*itr);
            int weight = get<2>(*itr);

            if (DP[p][k-1] != INT_MAX && DP[p][k-1] + weight < DP[u][k]) {
                DP[u][k] = DP[p][k-1] + weight;
            }
        }
        if (DP[dest][k] < minOfDest) {
            minOfDest = DP[dest][k];
        }
    }

    if (minOfDest != INT_MAX) {
        return minOfDest;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    for (size_t i = 0; i < TC; i++) {
        vector<tuple<int, int, int> > edges; // from, to, weight
        int V;
        cin >> V;
        for (size_t j = 0; j < V; j++) {
            int X;
            cin >> X;
            for (size_t k = 0; k < X; k++) {
                int vertex, weight;
                cin >> vertex >> weight;
                edges.push_back(make_tuple(j, vertex, weight));
            }
        }
        int Q;
        cin >> Q;
        for (size_t j = 0; j < Q; j++) {
            int from, to, limit;
            cin >> from >> to >> limit;
            cout << getMinPath(from, to, limit, edges, V) << endl;
        }
        cout << endl;
    }
}
