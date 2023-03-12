/* 最小全域木(プリム法) */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_NODE 100
#define UNREACABLE -1

using namespace std;

int adjmat[MAX_NODE][MAX_NODE];

//  プリムのアルゴリズムで最小全域木を構築する
//  MST: Minimun Spanning Tree
int32_t construct_MST(int n) {
    int16_t dist[n] = {0};  // V-Tの各頂点までの重みの最小値
    bool visited[n] = {false};  // 訪問済みか
    int32_t sum = 0;            // 重みの総和

    fill_n(dist, n, INT16_MAX);
    dist[0] = 0;  // 初期頂点は0

    int u, v;         // u: 次に訪問する頂点
    int16_t mincost;  // distの最小値
    while (true) {
        mincost = INT16_MAX;
        rep(i, n) {
            /* 未訪問の頂点から重みが最小のものを選択 */
            if (!visited[i] && dist[i] < mincost) {
                mincost = dist[i];
                u = i;
            }
        }

        if (mincost == INT16_MAX) {  // 全て訪問済み
            break;
        }

        visited[u] = true;
        sum += mincost;

        rep(v, n) {
            // 未訪問 && exist (u, v)
            if (!visited[v] && adjmat[u][v] != UNREACABLE) {
                if (adjmat[u][v] < dist[v]) {
                    dist[v] = adjmat[u][v];
                }
            }
        }
    }

    return (sum);
}

int main() {
    int n;  // 頂点数
    cin >> n;

    rep(i, n) {
        rep(j, n) { cin >> adjmat[i][j]; }
    }

    cout << construct_MST(n) << endl;
    return (0);
}