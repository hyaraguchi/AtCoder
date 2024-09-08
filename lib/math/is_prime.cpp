using namespace std;
typedef long long ll;

// 素数判定アルゴリズム
// 時間計算量: O(√n)

bool is_prime(ll n) {
    if (n <= 1) return false;
    else {
        for (ll i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
