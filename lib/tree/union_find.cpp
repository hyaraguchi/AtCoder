#include <vector>
using namespace std;

/*
 * Union-Find木
 * 参考: https://www.slideshare.net/chokudai/union-find-49066733
*/


// 0-index

struct UnionFind {
    vector<int> par;
    vector<int> rank;

    UnionFind(int N) : par(N), rank(N) {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void merge(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        if (rank[rx] == rank[ry]) rank[rx]++;
        par[ry] = rx;
    }

    bool is_same(int x, int y) {
        return root(x) == root(y);
    }
};


// UnionFind tree(N);
