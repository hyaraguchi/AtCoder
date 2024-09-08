#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;


/*
 * 個数制限付きナップサック問題
 * N 種類の数 a[i] がそれぞれ m[i] ずつある。
 * これらの中からいくつか選び、その総和をちょうど K にすることができるか判定せよ。
 * 
 * 【DPテーブル】
 * iループ中のdp[j] -> i番目間でで j を作るとき余る最大のi番目の数の個数。
 * 
 * 【答え】
 * if (DP[K] >= 0) then TRUE else FALSE
*/

int N, K;
const int MAX_N = 110;
int a[MAX_N], m[MAX_N];
const int MAX_K = 1.0e5 + 10; 
int dp[MAX_K];

void DPinit() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp[j] >= 0) {
                dp[j] = m[i];
            }
            else if (j < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;
            }
            else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    return;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> a[i] >> m[i];

    DPinit();

    cout << (dp[K] >= 0 ? "Yes" : "No") << endl;

    return 0;
}