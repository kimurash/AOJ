/* グラフの表現(隣接行列) */
/* 深さ優先探索 */
/* 幅優先探索 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

#define MAX_EDGE 100

void dfs(bool (*adjmat)[MAX_EDGE], int n);
void bfs(bool (*adjmat)[MAX_EDGE], int n);
bool contain(const vector<int> &vec, int elem);
void print_mat(bool (*mat)[MAX_EDGE], int m, int n);

int main() {
    int n;
    cin >> n;

    bool adjmat[MAX_EDGE][MAX_EDGE];
    fill(adjmat[0], adjmat[n], false);
/*  fill(first, last, value)
    firstからlastのひとつ手前までの要素にvalueを代入する */

    int u, v, outdeg;
    rep(i, n) {
        cin >> u >> outdeg;
        rep(j, outdeg) {
            cin >> v;
            adjmat[u - 1][v - 1] = true;
        }
    }

    // dfs(adjmat, n);
    bfs(adjmat, n);
    // print_mat(adjmat, n, n);
    return (0);
}

// Depth First Search
void dfs(bool (*adjmat)[MAX_EDGE], int n) {
    stack<int> yet;       // 未訪問の頂点
    vector<int> visited;  // 訪問済みの頂点

    yet.push(0);   // 初期頂点を入れる
    int visiting;  // 訪問中の頂点
    while (!yet.empty()) {
        visiting = yet.top();
        yet.pop();
        if (contain(visited, visiting)) {
            continue;
        }

        visited.push_back(visiting);
        // 頂点番号の小さいものから選択するため降順に積む
        for (int i = n - 1; i >= 0; i--) {
            // 隣接している && 未訪問
            if (adjmat[visiting][i] && !(contain(visited, i))) {
                yet.push(i);
            }
        }
    }

    rep(i, n) { cout << visited.at(i) + 1 << " "; }
    cout << endl;
    return;
}

void bfs(bool (*adjmat)[MAX_EDGE], int n) {
    queue<int> yet;      // 未訪問の頂点
    vector<int> peeked;  // 未訪問 + 訪問済み
    int dist[n];         // 初期頂点からの距離
    fill_n(dist, n, -1);

    // 初期頂点を両方に入れる
    yet.push(0);
    peeked.push_back(0);
    dist[0] = 0;

    int visiting;  // 訪問中の頂点
    while (!yet.empty()) {
        visiting = yet.front();
        yet.pop();
        rep(i, n) {
            // 隣接している && peekedに入っていない
            if (adjmat[visiting][i] && !(contain(peeked, i))) {
                yet.push(i);
                peeked.push_back(i);
                dist[i] = dist[visiting] + 1;
            }
        }
    }

    // rep(i, peeked.size()){ cout << peeked.at(i) + 1 << " "; }
    // cout << endl;
    rep(i, n) { printf("%d %d\n", i + 1, dist[i]); }
    return;
}

bool contain(const vector<int> &vec, int elem) {
    if (find(vec.begin(), vec.end(), elem) == vec.end()) {
        return (false);
    } else {
        return (true);
    }
}

void print_mat(bool (*mat)[MAX_EDGE], int m, int n) {
    rep(i, m) {
        cout << (int)mat[i][0];
        rep2(j, 1, n) { cout << " " << mat[i][j]; }
        cout << endl;
    }
}