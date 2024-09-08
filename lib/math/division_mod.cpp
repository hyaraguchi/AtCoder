#include <cmath>
using namespace std;
typedef long long ll;

/*
 * MODを割り算で使うときのライブラリ
 * https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a 
*/

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

ll modinv(ll n, ll mod) {
    return pow_mod(n, mod - 2, mod);
}


// (a/b) % MOD =  
// cout << a * modinv(b, MOD) % MOD << endl;