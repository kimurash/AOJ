/* コイン問題 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int search_best_coins(int *coin, int m, int n) {
    int best[m][n + 1];
/*  best[i][j]
    i番目までのコインを使ってj円支払うときのコインの最小枚数 */
    // [HACK]: uint8_tだとmin()関数に渡せなかった

    /* 1行目のみ埋める */
    best[0][0] = 0;
    rep2(j, 1, n + 1) {
        best[0][j] = (j + coin[0] - 1) / coin[0];  // ceil(n / c[0])
    }

    rep2(i, 1, m) {
        rep(j, n + 1) {
            if(j >= coin[i]){
            /* コインは何枚でも使用できるため
                best[i-1][j-coin[i]]としなくてよい */
                best[i][j] = min(best[i][j - coin[i]] + 1, best[i - 1][j]);
            } else{
                best[i][j] = best[i-1][j];
            }
        }
    }

    return (best[m-1][n]);
}

int main() {
    int n, m;  // 代金,整数の数
    cin >> n >> m;

    int coin[m];
    rep(i, m) { cin >> coin[i]; }

    cout << search_best_coins(coin, m, n) << endl;
    return (0);
}