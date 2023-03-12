/* 最小全域木(クラスカル法) */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

class Edge {
public:
    int src;          // 始点
    int target;       // 終点
    uint16_t weight;  // 重み

    Edge(int src = 0, int target = 0, uint16_t weight = 0)
        : src(src), target(target), weight(weight) {}  // コンストラクタ初期化子

    // constメンバ関数
    bool operator<(const Edge &e) const { return (this->weight < e.weight); }
};

class UnionFind {
private:
    std::vector<int> rank, parent;

public:
    // コンストラクタ
    UnionFind();
    UnionFind(int size) {
        rank.resize(size, 0);
        parent.resize(size, 0);
        for (int i = 0; i < size; i++) {
            this->make_set(i);
        }
    }

    // インスタンスメソッド
    void make_set(int x) {
        rank.at(x) = 0;
        parent.at(x) = x;
    }

    int find_set(int x) {
        if (parent.at(x) != x) {
            parent.at(x) = find_set(parent.at(x));
        }
        return (parent.at(x));
    }

    void unite(int x, int y) { this->link(find_set(x), find_set(y)); }

    void link(int x, int y) {
        if (rank.at(x) > rank.at(y)) {
            parent.at(y) = x;
        } else {
            parent.at(x) = y;
            if (rank.at(x) == rank.at(y)) {
                rank.at(y)++;
            }
        }
    }

    bool is_same(int x, int y) {
        return (this->find_set(x) == this->find_set(y));
    }
};

// クラスカルのアルゴリズムで最小全域木を構築する
//  MST: Minimun Spanning Tree
uint32_t construct_MST(vector<Edge>& edges, int V) {
    sort(all(edges));  // 辺を重みの昇順でソート

    int K = 0;                    // 全域木の辺数
    uint32_t total = 0;           // 重みの総和
    UnionFind uf = UnionFind(V);  // 全域木の辺を管理する素な集合

    rep(i, edges.size()) {
        Edge e = edges.at(i);
        if (!uf.is_same(e.src, e.target)) {  // 始点と終点が同じ集合に属さない
            uf.unite(e.src, e.target);
            total += e.weight;
            K++;
            if (K >= V) {
                break;
            }
        }
    }

    return(total);
}

int main() {
    int V, E;  // 頂点数,辺数
    cin >> V >> E;
    vector<Edge> edges;

    int s, t;
    uint16_t w;
    rep(i, E) {
        cin >> s >> t >> w;
        edges.push_back(Edge(s, t, w));
    }

    cout << construct_MST(edges, V) << endl;
    return (0);
}
