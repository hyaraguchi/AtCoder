using namespace std;
typedef long long ll;

// 繰り返し二乗法
// n^k % mod の値を求める。
//　O(log k)

ll pow_mod(ll n, ll k, ll mod) {
    if (k == 0) return 1;
    else if (k % 2 == 1) {
        return pow_mod(n, k-1, mod) * n % mod;
    }
    else {
        ll tmp = pow_mod(n, k/2, mod);
        return tmp * tmp % mod;
    }
}
