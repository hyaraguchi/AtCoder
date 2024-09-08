#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 * 二つの文字列の編集距離を求める.
 * 
 * 編集距離とは、以下３種類の操作によって、１つの文字列を別の文字列に変形するのに必要な手順の最小回数である.
 *
 * 挿入: 文字列に１つの文字を挿入する。
 * 削除: 文字列から１つの文字を削除する。
 * 置換: 文字列の中の１文字を別な文字に置き換える。
 *
*/

int edit_distance(string s, string t) {
    int sl = s.length();
    int tl = t.length();
    int dp[sl+1][tl+1];

    for (int i = 0; i <= sl; i++) dp[i][0] = i;
    for (int j = 0; j <= tl; j++) dp[0][j] = j;

    for (int i = 1; i <= sl; i++) {
        for (int j = 1; j <= tl; j++) {
            int w;
            if (s[i-1] == t[j-1]) w = 0;
            else w = 1;

            dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + w));
        }
    }

    return dp[sl][tl];
}