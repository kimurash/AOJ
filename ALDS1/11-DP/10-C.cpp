/* 最長共通部分列 */
/* Longest Common Subsequence */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

uint16_t lcs(const string &X, const string &Y) {
    uint16_t c[X.size() + 1][Y.size() + 1];

    rep(i, X.size() + 1) {
        rep(j, Y.size() + 1) {
            // 漸化式をそのまま実装
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (X.at(i - 1) == Y.at(j - 1)) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    return (c[X.size()][Y.size()]);
}

int main() {
    int q;
    cin >> q;

    string X, Y;
    rep(i, q) {
        cin >> X;
        cin >> Y;
        cout << lcs(X, Y) << endl;
    }
    return (0);
}