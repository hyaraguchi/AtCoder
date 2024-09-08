#include <map>
using namespace std;

// 配列xの最頻値を求める.(sizeは配列xの要素数)
// cls := 階級, freq := 度数

int mode(int x[], int size) {
    map<int, int> mp;
    int cls = 0;
    int freq = 0;
    for (int i = 0; i < size; i++) {
        mp[x[i]]++;
        if (freq < mp[x[i]]) {
            freq = mp[x[i]];
            cls = x[i];
        }
    }
    return cls;
}
