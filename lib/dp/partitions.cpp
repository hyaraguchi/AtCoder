#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

/*
 * 分割数
 * N 個の区別できない品物を、M 個以下に分割する方法の総数は？
 * 
 * 【DPテーブル】
 * dp[i][j] -> j の i 分割の総数
 * 
*/

int N, M;
const int MAX_NM = 1.0e4 + 10;
ll dp[MAX_NM][MAX_NM];
const int MOD = 1.0e9 + 7;

void DPinit() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            if (j >= i) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % MOD;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return;
}

int main() {
    cin >> N >> M;
    
    DPinit();

    cout << dp[M][N] << endl;

    return 0;
}