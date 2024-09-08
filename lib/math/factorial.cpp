using namespace std;
typedef long long ll;

// n! % MOD を計算するコード
// 前処理: O(n), クエリ: O(1)

const int MAX = 5.0e5 + 100;
const int MOD = 1.0e9 + 7;

ll fact[MAX];

void FACTinit() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
}


/****************************************************************************************/

// n! を愚直に計算するコード
// 20! までなら正確に計算できる

ll factorial(int n) {
    ll ret = 1;
    for (int i = 2; i <= n; i++) {
        ret *= i;
    }
    return ret;
}


