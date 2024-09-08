#include <vector>
using namespace std;

/*
 * Binary Indexed Tree
 * 別名：Fenwick Tree
 * 参考：http://hos.ac/slides/20140319_bit.pdf
 * 
 * ・N個の区間の和を保管する
 * ・変数の値を更新する：O(log N)時間
 * ・区間の和の計算
*/

// 1-index

// v[l] + v[l+1] + ... + v[r] の高速計算

// add(a, w) => v[a] += w

// sum(l, r) => v[l] + v[l+1] + ... + v[r]

template <class T> struct fenwick_tree {
    vector<T> bit;

    fenwick_tree(int N) : bit(N+1) {
        fill(bit.begin(), bit.end(), 0);
    }

    void add(int a, T w) {
        for (int x = a; x < (int)bit.size(); x += x & -x) {
            bit[x] += w; 
        }
    }

    T sum(int l, int r) {
        T sum_l = 0;
        for (int x = l-1; x > 0; x -= x & -x) {
            sum_l += bit[x];
        }
        T sum_r = 0;
        for (int x = r; x > 0; x -= x & -x) {
            sum_r += bit[x];
        }
        return sum_r - sum_l;
    }    
};

// fenwick_tree<ll> tree(N);