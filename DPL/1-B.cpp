/* ナップサック問題 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
// #define all(v) v.begin(), v.end()

using namespace std;

typedef struct item {
    int value;   // 価値
    int weight;  // 重さ
} Item;

int search_best_items(Item *items, int N, int W) {
    int best[N][W + 1];
    /* best[i][j]
        i番目までの品物を考慮して容量がjのナップサックに
        入れる場合の価値の合計の最大値 */
    // [HACK]: intだとmin()関数に渡せなかった

    /* 1行目だけ埋める */
    rep(j, W + 1) {
        if (items[0].weight <= j) {
            best[0][j] = items[0].value;
        } else {
            best[0][j] = 0;
        }
    }

    rep2(i, 1, N) {
        rep(j, W + 1) {
            if (items[i].weight <= j) {
                best[i][j] = max(best[i - 1][j - items[i].weight] + items[i].value,
                                 best[i - 1][j]);
            } else {
                best[i][j] = best[i - 1][j];
            }
            // cout << best[i][j] << " ";
        }
        // cout << endl;
    }

    return (best[N - 1][W]);
}

int main() {
    int N, W;  // 品物の数,ナップサックの容量
    cin >> N >> W;

    Item items[N];
    rep(i, N) {
        cin >> items[i].value >> items[i].weight;
        // cout << items[i].value << " " << items[i].weight << endl;
    }

    cout << search_best_items(items, N, W) << endl;
    return (0);
}