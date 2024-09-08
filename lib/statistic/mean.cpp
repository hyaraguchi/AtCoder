#include <vector>
using namespace std;

// vector<int> x の平均値を求める。

double mean(vector<int> x) {
    double n = x.size();
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i];
    }
    return sum/n;
}