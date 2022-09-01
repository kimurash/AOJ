/* トポロジカルソート */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_NODE 10000

using namespace std;

vector<int> adjlst[MAX_NODE];    // 隣接リスト
uint16_t indeg[MAX_NODE] = {0};  // 入次数
queue<int> order;                // トポロジカル順序

void tplg_sort(int V);
void bfs(bool *visited, int s);

int main() {
    int V, E;  // 頂点数,辺数
    cin >> V >> E;

    int s, t;
    rep(i, E) {
        cin >> s >> t;
        adjlst[s].push_back(t);
        indeg[t]++;
    }

    tplg_sort(V);
    return (0);
}

// トポロジカルソート
void tplg_sort(int V) {
    bool visited[V] = {false};

    // このループで見過ごされても
    // bfs()で入次数が0になった時点で訪問される
    rep(u, V) {
        // 入次数が0 && 未訪問
        if (indeg[u] == 0 && !visited[u]) {
            bfs(visited, u);
        }
    }

    rep(i, V) {
        cout << order.front() << endl;
        order.pop();
    }

    return;
}

// 初期頂点をsとした幅優先探索
// 入次数が0となった頂点を訪問する
void bfs(bool *visited, int s) {
    queue<int> yet;

    yet.push(s);
    while (!yet.empty()) {
        int u = yet.front();
        yet.pop();

        visited[u] = true;
        order.push(u);

        rep(i, adjlst[u].size()) {
            int v = adjlst[u].at(i);
            indeg[v]--; // 辺を削除
            if (indeg[v] == 0 && !visited[v]) {
                yet.push(v);
            }
        }
    }

    return;
}
