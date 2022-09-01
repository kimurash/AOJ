/* 最小コストソート */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_N 1000   // 最大荷物数
#define MAX_W 10000  // 重さの最大値

using namespace std;

/**
 * @param W: 荷物の重さ
 * @param n: 荷物の数
 * @param m_global: 入力全体の最小値
 *
 * @return 最小コスト
 */
uint32_t sort_by_min_cost(uint16_t *W, int n, uint16_t m_global) {
    uint16_t clone[n] = {0};    // 入力の複製
    bool visited[n] = {false};  // 訪問済みか

    /* 入力を複製してクイックソート */
    rep(i, n) { clone[i] = W[i]; }
    sort(clone, clone + n);

    int dest[MAX_W + 1] = {0};  // dest[w]: wが収まるべき添字
    rep(i, n) { dest[clone[i]] = i; }

    uint32_t min_cost = 0;
    rep(i, n) {
        if (visited[i]) {  // 訪問済みであれば
            continue;
        }

        int crrnt = i;             // 現在訪問している添字
        uint16_t len = 0;          // サイクルの長さ
        uint32_t sumw = 0;         // サイクル内の重さの合計
        uint16_t m_local = MAX_W;  // サイクル内の重さの最小値
        while (true) {
            visited[crrnt] = true;
            len++;
            uint16_t w = W[crrnt];
            sumw += w;
            m_local = min(m_local, w);

            crrnt = dest[w];
            if (visited[crrnt]) {
                break;
            }
        }

        // サイクルの最小コストを計算
        min_cost += min(sumw + (len - 2) * m_local,
                        sumw + m_local + (len + 1) * m_global);
    }

    return (min_cost);
}

int main() {
    int n;
    cin >> n;

    uint16_t W[n] = {0};
    uint16_t m_global = MAX_W;  // 入力全体の最小値
    rep(i, n) {
        cin >> W[i];
        m_global = min(m_global, W[i]);
    }

    uint32_t min_cost = sort_by_min_cost(W, n, m_global);
    cout << min_cost << endl;
    return (0);
}