#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 任意精度整数型（10^100以下）
#include <boost/multiprecision/cpp_int.hpp>
using Bint = boost::multiprecision::cpp_int;

int main() {
    // 小数の桁数の指定
    cout << fixed << setprecision(10);

    // 重複要素の削除
    vector<int> sample = {1, 1, 1, 3, 5, 3, 1, 1, 1, 1, 7};
    sort(sample.begin(), sample.end());
    auto result = unique(sample.begin(), sample.end());
    sample.erase(result, sample.end());

    // mapの走査
    map<string, int> mp;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        string key = itr->first;
        int val = itr->second;
    }

    // int -> char
    int cnt = 1;
    char aaa = '0' + cnt;

    // 切り上げ、切り捨て、四捨五入
    double xxx = 114.514;
    ceil(xxx); // 切り上げ、115.0
    floor(xxx); // 切り捨て、114.0
    round(xxx); // 四捨五入、115.0

    // 大文字 to 小文字、小文字 to 大文字
    char x = 'x';
    char Y = 'Y';
    (char)(x - ('a' - 'A')); // X
    (char)(Y + ('a' - 'A')); // y


    // テキストファイルから標準入力
    ifstream in("example_01.txt");
    cin.rdbuf(in.rdbuf());

    // テキストファイルに出力 (#include <fstream>)
    ofstream outputfile("test.txt");
    outputfile<<"test";
    outputfile.close();

    // 和集合・積集合
    set<int> a;
    set<int> b;
    set<int> aORb;
    set_union(a.begin(), a.end(),
              b.begin(), b.end(),
              inserter(aORb, aORb.end()));
    set<int> aANDb;
    set_intersection(a.begin(), a.end(),
                     b.begin(), b.end(),
                     inserter(aANDb, aANDb.end()));
        
    // 文字列の反転
    string S = "hello";
    reverse(S.begin(), S.end());

    // 行数不明の入力
    string SS;
    while (cin >> SS) {
        // 操作
    }

    // string のソート
    string tmp = "dabc";
    sort(tmp.begin(), tmp.end()); // tmp = "abcd";

    return 0;
}