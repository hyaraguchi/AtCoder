#include <vector>
using namespace std;
typedef long long ll;

// エラストテネスのふるい（nまでの素数を列挙する）
// 時間計算量：O(N log (log N)) ≒ O(N) 

// prime[i] -> i番目の素数 (1-index)
// is_prime[i] -> trueならiは素数

const int MAX_N = 1.0e5 + 10;
int prime[MAX_N];
bool is_prime[MAX_N];

// n以下の素数の個数
int sieve(int n) {
    int p = 1;
    for (int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p] = i;
            for (int j = 2*i; j <= n; j += i) is_prime[j] = false;
            p++;
        }
    }
    return p-1;
}

// 高速素因数分解