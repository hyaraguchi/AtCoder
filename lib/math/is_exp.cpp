using namespace std;
typedef long long ll;

/*
 * nがべき乗数かどうかを判定する関数。
 * べき乗数は、1以上の自然数をa, 2以上の自然数をbとして、a^bで表される数。
 * （例：10以下のべき乗数 ＝＞ 1, 4, 8, 9）
*/

bool isExp(ll n) {
    if (n == 1) return true;
    else {
        for (ll i = 2; i*i <= n; i++) {
            ll now = n;
            while (now % i == 0) {
                now /= i;
            }
            if (now == 1) return true;
        }
        return false;
    }
}
