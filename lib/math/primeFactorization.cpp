#include <vector>
using namespace std;
typedef long long ll;

// 素因数分解
// 例：12 => 2, 2, 3

vector<ll> primeFactorization(ll n) {
    vector<ll> ret;
    ll a = 2;
    while (n >= a * a) {
        if (n % a == 0) {
            ret.push_back(a);
            n /= a;
        } 
        else a++;
    }
    ret.push_back(n);
    return ret;
}

/*
   素因数の列挙
 
   vector<ll> pf = primeFactorization(n);
   auto result = unique(pf.begin(), pf.end());
   pf.erase(result, pf.end());
  
   pf = nの素因数を列挙したもの。
   例：12 => 2, 3
*/
