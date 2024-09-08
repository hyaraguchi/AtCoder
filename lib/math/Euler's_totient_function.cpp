#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

/*
 * オイラーのφ関数(Euler's totient function)
 * φ(n) = 自然数nに対して、nと互いに素である1以上n以下の自然数の個数。
 * （例：φ(6) = 2 → 1と5）
 * φ(n) = n * (1-1/p_1) * (1-1/p_2) * ... * (1-1/p_k)
 * ただし、p_iはnのi番目の素因数。
*/

vector<ll> primeFactorization(ll n) {
    vector<ll> ret;
    ll a = 2;
    while (n >= a * a) {
        if (n % a == 0) {
            ret.push_back(a);
            n /= a;
        } else {
            a++;
        }
    }
    ret.push_back(n);
    return ret;
}

ll totient_function(ll n) {
    ll ret = n;
    vector<ll> pf = primeFactorization(n);
    auto result = unique(pf.begin(), pf.end());
    pf.erase(result, pf.end());
    for (int i = 0; i < pf.size(); i++) {
        ret = ret * (pf[i] - 1) / pf[i];
    }
    return ret;
}
