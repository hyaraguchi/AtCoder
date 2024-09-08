using namespace std;
typedef long long ll;

/*
 * 負の数も考慮したmod。
 * C++ では、" % "を用いて余りを計算すると、答えが負数になる時がある。
 * (例： (-2) % 3 == -2)
 * 以下のプログラムを用いれば、余りを数学における定義通りに計算できる。
 * (例: (-2) % 3 == 1)
 * 
*/ 

ll neg_mod(ll n, ll mod)  {
    ll res = n % mod;
    if (res < 0) res += mod;
    return res;
}
