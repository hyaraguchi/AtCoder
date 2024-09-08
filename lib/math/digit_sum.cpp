using namespace std;
typedef long long ll;

// 桁和（正の整数nの各桁の数字の和を返す）

int digit_sum(ll n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
