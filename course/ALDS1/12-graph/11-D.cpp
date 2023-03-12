/* 連結成分 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

#define MAX_USER 100000
#define YET_LABELED 0

vector<int> adjlst[MAX_USER];          // 隣接リスト
int labels[MAX_USER] = {YET_LABELED};  // 各頂点のラベル

void dfs(int init, int label);
void print_lst(int n);

int main() {
    int n, m;  // ユーザ数,関係の数
    cin >> n >> m;

    int s, t;
    rep(i, m) {
        cin >> s >> t;
        adjlst[s].push_back(t);
        adjlst[t].push_back(s);
    }

    // print_lst(n);

    /* ラベリング */
    int label = 1;
    rep(i, n) {
        if (labels[i] == YET_LABELED) {
            // 頂点iからDFSで連結成分を抽出
            dfs(i, label);
            label++;
        }
    }

    int q;  // 質問の数
    cin >> q;
    rep(i, q) {
        cin >> s >> t;
        if (labels[s] == labels[t]) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return (0);
}

/**
 * @brief
 * 深さ優先探索による連結成分のラベリング
 * @param init 初期頂点
 * @param label 使用するラベル番号
 */
void dfs(int init, int label) {
    stack<int> yet;  // 未訪問の頂点
    // ラベルの値で訪問済みか判定できる
    // vector<int> visited;

    yet.push(init);  // 初期頂点を入れる
    int visiting;    // 訪問中の頂点
    while (!yet.empty()) {
        visiting = yet.top();
        yet.pop();
        if (labels[visiting] != YET_LABELED) {
            continue;
        }

        // visited.push_back(visiting);
        labels[visiting] = label;

        int adj;  // visitingと隣接している頂点
        rep(i, adjlst[visiting].size()) {
            adj = adjlst[visiting].at(i);
            if (labels[adj] == YET_LABELED) {  // 未訪問
                yet.push(adj);
            }
        }
    }

    return;
}

void print_lst(int n) {
    rep(i, n) {
        cout << "[" << i << "]:";
        rep(j, adjlst[i].size()) { cout << adjlst[i].at(j) << "-"; }
        cout << endl;
    }

    return;
}