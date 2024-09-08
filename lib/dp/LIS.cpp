#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

/*
 * 最長増加部分列問題
 * 長さ N の数列 {a[i]} がある。
 * この数列の増加部分列のうち、最長のものを求める。
 * 
 * 【DPテーブル】
 * dp[i] -> 最後が a[i] であるような最長の増加部分列の長さ
 * 
*/

int N;
const int MAX_N = 1.0e5 + 10;
ll a[MAX_N];
ll dp[MAX_N];
const int INF = 1.0e9;

ll LIS() {
    for (int i = 0; i < N; i++) dp[i] = INF;

    for (int i = 0; i < N; i++) {
        *lower_bound(dp, dp + N, a[i]) = a[i];
    }

    return (ll)(lower_bound(dp, dp + N, INF) - dp);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];

    cout << LIS() << endl;

    return 0;
}