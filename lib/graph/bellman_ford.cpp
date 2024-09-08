#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int src, dst, weight;
};
int V, E, r;
const int MAX_V = 1.0e5 + 10;
const int MAX_E = 1.0e5 + 10;
Edge es[MAX_E];
int d[MAX_V];
const int INF = 1.0e9;

bool bellman_ford(int s) {
    fill(d, d+V+1, INF);
    d[s] = 0;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            Edge e = es[j];
            if (d[e.src] != INF && d[e.dst] > d[e.src] + e.weight) {
                d[e.dst] = d[e.src] + e.weight;
                if (i == V-1) return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> V >> E >> r;
    for (int i = 0; i < E; i++) {
        int s, t, dis;
        cin >> s >> t >> dis;
        Edge e = {s, t, dis};
        es[i] = e;
    }

    if (bellman_ford(r)) {
        for (int i = 0; i < V; i++) {
            if (d[i] == INF) cout << "INF" << endl;
            else cout << d[i] << endl;
        } 
    }
    else {
        cout << "NEGATIVE CYCLE" << endl;
    }
    
    return 0;
}
