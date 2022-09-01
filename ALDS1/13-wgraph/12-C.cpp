/*
    単一始点最短経路
    - 隣接リスト
    - 優先度付きキュー
*/
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_NODE 100000

using namespace std;

// (節番号,重み) | (最短距離,節番号)
typedef pair<int, int> dest;

// 隣接リスト(節番号,重み)
vector<dest> adjlst[MAX_NODE];

void find_SSSP(uint32_t *dist, int n) {
    bool decided[n] = {false};

    // 最小値から取り出す優先度付きキュー(最短距離,節番号)
    priority_queue<dest, vector<dest>, greater<dest> > PQ;
    PQ.push(make_pair(0, 0));  // 初期頂点を挿入
    dist[0] = 0;

    int u, v;
    int dmin, weight;
    while (!PQ.empty()) {
        tie(dmin, u) = PQ.top();
        PQ.pop();

        decided[u] = true;
        // 取り出した最小値が最短でなければ無視
        // 先に最短の要素が取り出されるはず
        if (dist[u] < dmin) {
            continue;
        }

        rep(i, adjlst[u].size()) {
            tie(v, weight) = adjlst[u].at(i);
            if (decided[v]) {
                continue;
            }

            /* 最短距離の更新 */
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                PQ.push(make_pair(dist[v], v));
            }
        }
    }

    return;
}

int main() {
    int n;  // 頂点数
    cin >> n;

    int u, v;
    int outdeg, weight;
    rep(i, n) {
        cin >> u >> outdeg;
        rep(j, outdeg) {
            cin >> v >> weight;
            adjlst[u].push_back(make_pair(v, weight));
        }
    }

    uint32_t dist[n];
    fill_n(dist, n, UINT32_MAX);
    find_SSSP(dist, n);
    rep(i, n) { printf("%d %u\n", i, dist[i]); }

    return (0);
}