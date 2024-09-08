#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 * LCS(最長共通部分配列: Longest Common Subsequence)
 * SとTの要素から順番を保ったまま任意の文字を取り出して、
 * 同一となる文字列のうち、最長のもの。
 * （例：S = "axyb", T = "abyxb" => "axb" または "ayb"）
*/

string LCS(string s, string t) {
    int sl = s.length();
    int tl = t.length();
    int dp[sl+1][tl+1];

    for (int i = 0; i <= sl; i++) dp[i][0] = 0;
    for (int j = 0; j <= tl; j++) dp[0][j] = 0;

    for (int i = 1; i <= sl; i++) {
        for (int j = 1; j <= tl; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1] + 1));
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // return dp[sl][tl]; // 共通部分文字列の長さを求める. 

    string ret = "";
    int i = sl, j = tl;
    while (i > 0 && j > 0) {
        if (dp[i-1][j] == dp[i][j]) i--;
        else if (dp[i][j-1] == dp[i][j]) j--;
        else {
            ret = s[i-1] + ret;
            i--;
            j--;
        }
    }

    return ret;
}

int main() {
    string S, T;
    cin >> S >> T;

    cout << LCS(S, T) << endl;

    return 0;
}
