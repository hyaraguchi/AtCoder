#include <algorithm>
using namespace std;
typedef long long ll;

/* 
 * ユークリッドの互除法（aとbの最大公約数を返す）
 * LCM * GCD = a * b (LCM: 最小公倍数)
*/

ll gcd(ll a, ll b) {
    ll large = max(a, b);
    ll small = min(a, b);
    if (small == 0) return large;
    else return gcd(small, large % small);
}


/*
    n個の自然数のLCM.
  
    ll a[N];
    ll LCM = a[0];
    for (int i = 1; i < N; i++) {
        ll GCD = gcd(LCM, a[i]);
        LCM = LCM * a[i] / GCD;
    }
   
    LCM = a[0], ... a[N] の最小公倍数。
*/

/*
    n個の自然数のGCD

    ll GCD = A[0];
    for (int i = 1; i < N; i++) {
        GCD = gcd(GCD, A[i]);
    }

*/

/***************************************************************************/

/*
 * 拡張ユークリッド互除法
 * ax + by = c の整数解(x, y)を求める。
 * （注：c は gcd(a, b) で割り切れなければならない）
*/

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

/*

【使い方】

int main() {
    ll x, y;
    extGCD(x, y);
    cout << x << y << endl;
}

*/