#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;


int main() {
    // {0, 1, ..., N-1} のように昇順ソート済みの配列を用意する.
    int N = 10;
    vector<int> v(N);
    iota(v.begin(), v.end(), 0);
    // 順列が生成できる限り, ループし続ける.
    do {
        // 順列に対する操作.
    } while (next_permutation(v.begin(), v.end()));

}