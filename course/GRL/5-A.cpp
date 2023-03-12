/* 木の直径 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_NODE 100000  // 節点数の最大値
#define INFTY -1

using namespace std;

class Edge {
public:
    int dst;     // 終点
    int weight;  // 重み

    Edge() {}
    Edge(int d, int w) : dst(d), weight(w) {}
};

vector<Edge> adjlst[MAX_NODE];  // 隣接リスト

// 初期頂点sから最も遠い節点を深さ優先探索で求める
pair<int, int> find_longest(int s, int n) {
    queue<int> yet;  // 未訪問の頂点
    int dist[n];     // 初期頂点からの距離

    // 訪問済みかはこの値に基づいて判定する
    fill_n(dist, n, INFTY);

    // 初期頂点を両方に入れる
    yet.push(s);
    dist[s] = 0;

    int visiting;  // 訪問中の頂点
    pair<int, int> farthest(s, 0);
    while (!yet.empty()) {
        visiting = yet.front();
        yet.pop();

        Edge adj;  // visitingと隣接している頂点
        rep(i, adjlst[visiting].size()) {
            adj = adjlst[visiting].at(i);
            if (dist[adj.dst] == INFTY) {  // 目撃していない頂点であれば
                dist[adj.dst] = dist[visiting] + adj.weight;
                if (farthest.second < dist[adj.dst]) {  // 最遠頂点の更新
                    farthest = make_pair(adj.dst, dist[adj.dst]);
                }
                yet.push(adj.dst);
            }
        }
    }

    return (farthest);
}

int main() {
    int n;  // 節点数
    cin >> n;

    int s, t, w;
    rep(i, n - 1) {
        cin >> s >> t >> w;

        adjlst[s].push_back(Edge(t, w));
        adjlst[t].push_back(Edge(s, w));
    }

    int x, y, diam;
    tie(x, ignore) = find_longest(0, n);
    tie(y, diam) = find_longest(x, n);
    
    cout << diam << endl;

    return (0);
}