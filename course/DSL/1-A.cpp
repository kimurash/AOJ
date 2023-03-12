/* 互いに素な集合 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

/* 将来のためと考えてライブラリを作成したが
   提出するコードにクラスの定義がないとエラーになる */
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

int main() {
    int n, q;  // 要素数,クエリ数
    cin >> n >> q;
    UnionFind ds = UnionFind(n);

    int qtype, x, y;
    rep(i, q) {
        cin >> qtype >> x >> y;
        switch (qtype) {
            case 0:  // unite
                ds.unite(x, y);
                break;
            case 1:  // same
                cout << (int)ds.is_same(x, y) << endl;
                break;
            default:
                cout << "Unknown Query" << endl;
                break;
        }
    }

    return (0);
}