#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // vectorの降順ソート
    vector<int> a = {1, 2, 3};
    sort(begin(a), end(a), greater<>());

    // 配列の初期化
    int dp[100][100];
    memset(dp, 0, sizeof(dp));

    // 10進数 to 2進数
    bitset<8> bt(5); // 00000101

    return 0;
}