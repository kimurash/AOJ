/* 8クイーン問題 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define N 8  // クイーンの数

#define RAID 1  // 襲撃されている
#define NOT_RAID -1

using namespace std;

bool occupied[N][N];  // 既に配置されているクイーンの位置
int8_t row[N], col[N], rdiag[2 * N - 1], ldiag[2 * N - 1];
/*
    row[i]: 何列目のQueenに襲撃されている/いないか
    col[i]: 列iが襲撃されているか
    rdiag[i]: 左下方向の列iが襲撃されているか
    ldiag[i]: 右下方向の列iが襲撃されているか
*/

// 配列変数を初期化
void initialize() {
    rep(i, N) {
        row[i] = col[i] = NOT_RAID;
        rep(j, N) { occupied[i][j] = false; }
    }

    rep(i, 2 * N - 1) { rdiag[i] = ldiag[i] = NOT_RAID; }
}

// 盤面を表示する関数
void print_board() {
    rep(i, N) {
        rep(j, N) {
            // 既に配置されたクイーンの位置を満たしているか
            if (occupied[i][j] && row[i] != j) {
                return;
            }
        }
    }

    rep(i, N) {
        rep(j, N) { cout << ((row[i] == j) ? 'Q' : '.'); }
        cout << endl;
    }
    return;
}

// ヒューリスティック探索でクイーンの配置を決定
void heuristic(int r) {
    if (r == N) {
        print_board();
        return;
    /* 入力に対する解はただ1つ存在するため
        盤面が2回以上表示されることはない */
    }

    rep(c, N) {
        // (r, c)が他のQueenに襲撃されている場合は無視
        if (col[c] == RAID || rdiag[r + c] == RAID ||
            ldiag[r - c + (N - 1)] == RAID) {
            // (N-1)列目から(r-c)ズレた列
            continue;
        }
        // (r, c)にQueenを配置
        // <=> r行目はc列のQueenに襲撃されている
        row[r] = c;
        col[c] = rdiag[r + c] = ldiag[r - c + (N - 1)] = RAID;

        // 次の行を試す
        heuristic(r + 1);

        // (r, c)の配置されているQueenを取り除く
        row[r] = col[c] = rdiag[r + c] = ldiag[r - c + (N - 1)] = NOT_RAID;
    }

    return;  // クイーンの配置に失敗
}

int main() {
    initialize();

    int k;
    cin >> k;
    int r, c;
    rep(i, k) {
        cin >> r >> c;
        occupied[r][c] = true;
    }

    heuristic(0);
    return (0);
}