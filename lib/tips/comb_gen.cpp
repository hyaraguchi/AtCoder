#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

/*
 * 組み合わせの列挙.
 * n枚のカードからk枚選ぶ方法を列挙する.(nCk 通り)
 * 
 * 例：comb_gen(10, 5, {}, 10)
 *    -> {0, 1, 2, 3, 4} ~ {5, 6, 7, 8, 9} までの252通りの配列を重複なく,comb_vecに格納する.
 * 
 * nPk の列挙は, comb_vecに対して, next_permutation を使えば列挙できる.
*/

vector<vector<int> > comb_vec;

void comb_gen(int n, int k, vector<int> vec, int mx) {
    if (n == 0 && k == 0) {
        comb_vec.push_back(vec);
    }
    else {
        if (n > k) {
            comb_gen(n-1, k, vec, mx);
        }
        if (k != 0) {
            vec.push_back(mx - n);
            comb_gen(n-1, k-1, vec, mx);
        }
    }
    return;
}

int main() {
    comb_gen(10, 5, {}, 10);
    for (int i = 0; i < comb_vec.size(); i++) {

        for (int j = 0; j < comb_vec[i].size(); j++) {
            cout << comb_vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << comb_vec.size() << endl;

    return 0;
}