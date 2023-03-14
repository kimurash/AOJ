/* 8パズル問題 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define N_COL 3
#define N_PANEL 9

using namespace std;

// 定値オブジェクト(本来は全て大文字にすべき)
const int dr[] = {-1, 0, 1, 0};           // 行方向の移動量
const int dc[] = {0, 1, 0, -1};           // 列方向の移動量
const char dir[] = {'u', 'r', 'd', 'l'};  // パネルを動かす方向

typedef struct puzzle {
    // この配列が末尾を除いて昇順になればよい
    int panel[N_PANEL];  // 3x3のパズルを1次元配列で表現
    int space;           // スペースの位置
    string prcs = "";    // パネルを動かす手順

    // mapのkeyとして構造体を使う場合は>演算子をオーバーロードする必要がある
    bool operator<(const struct puzzle &pzl) const {
        rep(i, N_PANEL) {
            if (this->panel[i] == pzl.panel[i]) {
                continue;
            } else {
                return (this->panel[i] < pzl.panel[i]);
            }
        }
        return (false);
    }
} Puzzle;

// パネルが昇順になっているか判定
bool is_target(Puzzle &pzl) {
    // cout << pzl.prcs << endl;
    rep(i, N_PANEL - 1) {
        if (pzl.panel[i] != (i + 1)) {
            return (false);
        }
    }

    return (true);
}

string bfs(Puzzle &init) {
    queue<Puzzle> yet;         // 未訪問のパズル
    map<Puzzle, bool> peeked;  // 訪問済み + 未訪問

    // 初期パズルを両方に入れる
    init.prcs = "";
    yet.push(init);
    peeked[init] = true;

    Puzzle visiting, adj;  // 訪問中とそれに隣接するパズル
    while (!yet.empty()) {
        visiting = yet.front();
        yet.pop();

        if (is_target(visiting)) {
            return (visiting.prcs);
        }

        int sr = visiting.space / N_COL;  // スペースの行
        int sc = visiting.space % N_COL;  // スペースの列
        // printf("sx:%d\tsy:%d\n", sr, sc);
        rep(i, 4) {
            int tr = sr + dr[i];
            int tc = sc + dc[i];
            // printf("tr:%d + %d = %d\n", sr, dr[i], tr);
            // printf("tc:%d + %d = %d\n", sc, dc[i], tc);

            if (tc < 0 || tr < 0 || tc >= N_COL ||
                tr >= N_COL) {  // パズルをはみ出す
                continue;
            }

            adj = visiting;
            // パネルを移動させる
            swap(adj.panel[visiting.space], adj.panel[tr * N_COL + tc]);
            adj.space = tr * N_COL + tc;

            if (!peeked[adj]) {  // 未目撃であれば
                adj.prcs += dir[i];
                yet.push(adj);
                peeked[adj] = true;
            }
        }
    }

    // never reached
    // because given puzzle must be solved.
    return ("unsolvable");
}

int main() {
    Puzzle init;

    rep(i, N_PANEL) {
        cin >> init.panel[i];
        if (init.panel[i] == 0) {
            init.space = i;
        }
    }

    cout << bfs(init).size() << endl;
    return (0);
}