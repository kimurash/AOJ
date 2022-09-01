/*
    単一始点最短経路
    - 隣接行列
*/
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_NODE 100

using namespace std;

uint32_t adjmat[MAX_NODE][MAX_NODE];  // 隣接行列

//  ダイクストラのアルゴリズムで最短経路を求める
//  SSSP: Single Source Shortest Path
void find_SSSP(uint32_t *dist, int n) {
    bool decided[n] = {false};  // 最短パスが確定済みか

    fill_n(dist, n, UINT32_MAX);
    dist[0] = 0;  // 初期頂点は0

    int u, v;
    uint32_t mincost;
    while (true) {
        mincost = UINT32_MAX;
        /*  距離が最小の頂点を求める */
        rep(i, n) {
            if (!decided[i] && dist[i] < mincost) {
                mincost = dist[i];
                u = i;
            }
        }

        if (mincost == UINT32_MAX) {  // 全ての最短経路が確定済み
            break;
        }
        decided[u] = true;

        rep(v, n) {
            // 未確定 && exist (u, v)
            if (!decided[v] && adjmat[u][v] != UINT32_MAX) {
                if (dist[u] + adjmat[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjmat[u][v];
                }
            }
        }
    }

    return;
}

int main() {
    int n;  // 頂点数
    cin >> n;
    fill(adjmat[0], adjmat[n], UINT32_MAX);

    int u, v;
    int outdeg;  // 出次数
    rep(i, n) {
        cin >> u >> outdeg;
        rep(j, outdeg) {
            cin >> v;
            cin >> adjmat[u][v];
        }
    }

    uint32_t dist[n];  // 始点から各頂点までの最短距離
    find_SSSP(dist, n);

    rep(i, n){
        printf("%d %u\n", i, dist[i]);
    }
    return(0);
}