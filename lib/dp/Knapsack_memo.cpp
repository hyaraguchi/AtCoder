#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, W;
ll w[110], v[110];
ll dp[110][100100];

ll rec_dp(ll i, ll j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    ll res;
    if (i == n) {
        res = 0;
    } else if (j < w[i]) {
        res = rec_dp(i+1, j);
    } else {
        res = max(rec_dp(i+1, j), rec_dp(i+1, j-w[i]) + v[i]);
    }
    return dp[i][j] = res;
}

int main() {

    memset(dp, -1, sizeof(dp));
 
    cout << rec_dp(0, W) << endl;

    return 0;
}