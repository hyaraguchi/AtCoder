#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

/*
 * ワーシャルフロイド法 
 * 最短経路探索アルゴリズム。
 * 負の閉路がない限り、負の辺があっても正常に動作する。
 * O(V^3)
 * k -> 経由する頂点
 * i -> 始点
 * j -> 終点
 * d -> in:隣接行列、out:d[i][j]=iからjまでの最短距離
*/

int V;
const int MAX_V = 110;
int d[MAX_V][MAX_V]; 
const int INF = 1.0e9;

void warshall_floyd(int n) {
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++) {
            if (d[i][k] == INF) continue; 
            for (int j = 0; j < n; j++) {
                if (d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return;
}

int main() {
    // 0-index
    cin >> V;
    // d[V][V]の初期化
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    // 入力（略）

    // ワーシャルフロイド法の実行
    warshall_floyd(V);

    // d[i][i] が負なら、負の閉路が存在する
    bool neg_circle = false;
    for (int i = 0; i < V; i++) {
        if (d[i][i] < 0) {
            neg_circle = true;
        }
    }

    return 0;
}