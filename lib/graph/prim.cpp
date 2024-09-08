#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

/*
 * プリム法(Prim's algorithm)
 * 貪欲法により、最小全域木の必要最小コストを求める。
 * 入力: 重み付きグラフ
 * 出力: 必要最小コスト
 * time: O(E log V)
*/

struct Edge {
    int dst;
    ll weight;
};
int V, E;
const int MAX_V = 1.0e5 + 10;
vector<Edge> G[MAX_V];
ll d[MAX_V];
const int INF = 1.0e9;

ll prim(int s) {
    using P = pair<ll, int>;

    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));
    vector<bool> visited(V, false);
    ll total = 0;

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (visited[v]) continue;
        visited[v] = true;
        total += p.first;

        for (int i = 0; i < G[v].size(); i++) {
            Edge e = G[v][i];
            if (d[e.dst] > e.weight) {
                d[e.dst] = e.weight;
                que.push(P(d[e.dst], e.dst));
            }
        }
    }
    return total;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        Edge e_s = {t, w};
        G[s].push_back(e_s);
        Edge e_t = {s, w};
        G[t].push_back(e_t);
    }

    // グラフGの最小全域木のコスト
    cout << prim(0) << endl;
       
    return 0;
}