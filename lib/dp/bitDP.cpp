#include <bits/stdc++.h>
using namespace std;

// 頂点数：V, 辺数：E, 隣接行列：d
int V, E;
const int MAX_V = 15;
const int INF = 1.0e9;
int d[MAX_V][MAX_V];

// DPテーブル
int dp[1 << MAX_V][MAX_V];

void update() {
    // DPテーブルの初期化
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = INF;
        }
    }

    // 漸化式にしたがってDPテーブルを更新
    dp[(1 << V) - 1][0] = 0;
    for (int i = (1 << V) - 2; i >= 0; i--) {
        for (int j = 0; j < V; j++) {
            for (int k = 0; k < V; k++) {
                if ((i >> k & 1) == 0) {
                    dp[i][j] = min(dp[i][j], dp[i | (1 << k)][k] + d[j][k]);
                }
            }
        }
    }
    return;
}

int main() {
    // 入力
    cin >> V >> E;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    for (int i = 0; i < E; i++) {
        int s, t, dis;
        cin >> s >> t >> dis;
        d[s][t] = dis;
    }

    // DPテーブルの更新
    update();

    // 最短経路の距離を出力する。条件を満たす経路が存在しない時、-1を出力する。
    cout << (dp[0][0] < INF ? dp[0][0] : -1) << endl;    
    
    return 0;
}
