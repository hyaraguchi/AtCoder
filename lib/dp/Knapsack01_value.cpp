#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

/*
 * 01ナップサック問題（価値）
 * 重みの総和 W 以下になるようにナップサックにつめられるアイテムの価値の最大値
 * 
 * 【DPテーブル】
 * dp[i][j] -> (i-1)番目までのアイテムから価値の総和がjとなるように選んだときの重みの最小値
 * 
 * 出力
 * dp[0][W] -> 重みが W 以下の価値の最大値
 * 
*/

int N, W;
const int MAX_N = 110;
const int MAX_V = 110;
ll w[MAX_N], v[MAX_N];
ll dp[MAX_N][MAX_N * MAX_V];
const int INF = 1.0e9;

void DPinit() {
    for (int j = 0; j < MAX_N * MAX_V; j++) {
        dp[0][j] = INF;
    }
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= MAX_N * MAX_V; j++) {
            if (j < v[i]) {
                dp[i+1][j] = dp[i][j];
            }
            else {
                dp[i+1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }
    return;
}

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; i++) cin >> v[i] >> w[i];

    DPinit();

    ll ans = 0;
    for (int j = 0; j <= MAX_N * MAX_V; j++) {
        if (dp[N][j] <= W) ans = j;
    }

    cout << ans << endl;

    return 0;
}

