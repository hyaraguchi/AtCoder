#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int dst, weight;
};
int V, E;
const int MAX_V = 1.0e5 + 10;
vector<Edge> G[MAX_V];
int d[MAX_V];
const int INF = 1.0e9;

void dijkstra(int s) {
    using P = pair<int, int>;

    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V+1, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i = 0; i < G[v].size(); i++) {
            Edge e = G[v][i];
            if (d[e.dst] > d[v] + e.weight) {
                d[e.dst] = d[v] + e.weight;
                que.push(P(d[e.dst], e.dst));
            }
        }
    }
    return;
}

int main() {
    cin >> V;
    int E;
    cin >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Edge e = {b, c};
        G[a].push_back(e);
    }
    dijkstra(0);
    for (int i = 0; i < V; i++) {
        if(d[i] != INF)
            cout << "0から" << i << "までのコスト: " << d[i] << endl;
    }
}