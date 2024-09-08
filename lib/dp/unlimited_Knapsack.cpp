#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

/*
 * 重さと価値がそれぞれ wi,vi であるような商品が N 個ある. 
 * 重さの総和が W を超えないに商品を選んだ時の,価値の総和の最大値を求めよ.
 * ”ただし,同じ商品を幾つでも選ぶことができる.”
 * 
 * 商品の重複を許したナップサック問題.
 * 
 * 【出力】
 * ・dp[j] => 重さの総和が j を超えない時の, 価値の総和の最大値.
 * 
*/

int N, W;
ll w[110], v[110];
const int MAX_W = 1.0e4 + 10;
ll dp[MAX_W];

void DPinit() {
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++) {
        for (int j = w[i]; j <= W; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return;
}

/*

重さの総和が W 以上となる商品の選び方のうち, 価値の総和の最小なもの.

void DPinit() {
    for (int i = 0; i <= W; i++) dp[i] = 1.0e9;
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = w[i]; j <= W; j++) {
            dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return;
}

*/

/*

重さの総和がぴったり W となる商品の選び方のうち, 価値の総和が最大のもの.
（そのような選び方がない場合, -1 を値として返す.）

void DPinit() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        dp[w[i]] = max(dp[w[i]], v[i]);
    }

    for (int i = 0; i < MAX_W; i++) {
        for (int j = 0; j < MAX_W - i; j++) {
            dp[i+j] = max(dp[i+j], dp[i]+dp[j]);
        }
    }
    return;
}

*/

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; i++) cin >> v[i] >> w[i];

    DPinit();

    cout << dp[W] << endl;

    return 0;
}