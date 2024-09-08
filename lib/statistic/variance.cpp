#include <vector>
using namespace std;

// vector<int> x の分散を求める。

double mean(vector<int> x) {
    double n = x.size();
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i];
    }
    return sum/n;
}

double variance(vector<int> x) {
    double n = x.size();
    double mu = mean(x);
    double d_sum = 0;
    for (int i = 0; i < n; i++) {
        d_sum += (x[i] - mu)*(x[i] - mu);
    }
    return d_sum/n;
}