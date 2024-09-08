#include <vector>
using namespace std;

/*
 * 重みつきUnion-Find木
 * 参考: https://qiita.com/drken/items/cce6fc5c579051e64fab
*/

struct WeightedUnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> diff_weight;

    WeightedUnionFind(int N) : par(N), rank(N), diff_weight(N) {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
            diff_weight[i] = 0;
        }
    }

    int root(int x) {
        if (par[x] == x) return x;
        else {
            root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = root(par[x]);
        }
    }

    int weight(int x) {
        root(x);
        return diff_weight[x];
    }

    int diff(int x, int y) {
        return weight(y) - weight(x);
    }

    void merge(int x, int y, int w) {
        w -= diff(x, y);
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) {
            swap(rx, ry);
            w = -w;
        }
        if (rank[rx] == rank[ry]) rank[rx]++;
        par[ry] = rx;
        diff_weight[ry] = w;
    }

    bool is_same(int x, int y) {
        return root(x) == root(y);
    }    
};

