#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

/*
 * 重複組合せ
 * N 種類の品物があり、i 番目の品物は a[i] 個ある。
 * 異なる種類の品物は区別できるが、同じ種類の品物は区別できない。
 * これらの品物の中から、m 個選ぶ組合せの総数から MOD で割ったあまりを求めよ。
 * 
 * [DPテーブル]
 * dp[i][j] -> i番目までの品物からj個選ぶ組み合わせの総数
 * 
*/

int N, M;
const int MAX_N = 1.0e4 + 10;
const int MAX_M = 1.0e4 + 10;
ll a[MAX_N];
ll dp[MAX_N][MAX_M];
const int MOD = 1.0e9 + 7;

void DPinit() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            if (j - 1 - a[i] >= 0) {
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]]) % MOD;
            }
            else {
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) % MOD;
            }
        }
    }
    return;
}

