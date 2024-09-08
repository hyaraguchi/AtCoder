#include <vector>
#include <cmath>
using namespace std;

/* 
 * ミンコフスキー距離(Minkowski distance)
 * Dxy = {sum of (|x_i - y_i|^p) } ^ (1/p)
 * p = 1 のとき → マンハッタン距離（碁盤の目）
 * p = 2 のとき → ユークリッド距離（二次元平面）
 * p = ∞ のとき → チェビシェフ距離（）
*/ 

double Minkowski(vector<int> x, vector<int> y, double p) {
    double n = x.size();
    double p_sum = 0;
    for (int i = 0; i < n; i++) {
        p_sum += pow(abs(x[i] - y[i]), p);
    }
    return pow(p_sum, 1/p);
}

double Minkowski_INF(vector<int> x, vector<int> y) {
    double n = x.size();
    double ret = 0;
    for (int i = 0; i < n; i++) {
        ret = max((double)abs(x[i] - y[i]), ret);
    }
    return ret;
}
