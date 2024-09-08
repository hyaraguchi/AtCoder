#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

/*
 * 01ナップサック問題（重み）
 * 重みの総和 W 以下になるようにナップサックにつめられるアイテムの価値の最大値
 * 
 * 【DPテーブル】
 * dp[i][j] -> i番目以降のアイテムから重みの総和がj以下となるように選んだときの価値の最大値
 * 
 * 出力
 * dp[0][W] -> 重みが W 以下の価値の最大値
 * 
*/

int N, W;
ll w[110], v[110];
const int MAX_W = 1.0e4 + 10;
ll dp[110][MAX_W];

void DPinit() {
    memset(dp, 0, sizeof(dp));

    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i+1][j];
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i+1][j - w[i]] + v[i]);
            }
        }
    }
    return;
}

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; i++) cin >> v[i] >> w[i];

    DPinit();

    cout << dp[0][W] << endl;

    return 0;
}
