/*
    テーマ: キュー
    問題: ラウンドロビンスケジューリング
*/
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    queue<pair<string, int32_t> > procs;
    string name;
    int32_t time;
    rep(i, n) {
        cin >> name >> time;
        procs.push(make_pair(name, time));
    }

    int32_t elapsed = 0;          // 経過時間
    pair<string, int32_t> front;  // 先頭要素
    while (!procs.empty()) {      // 空になるまで
        /* 先頭要素の取り出し */
        front = procs.front();
        procs.pop();

        int32_t remain = front.second;  // 残り必要時間
        if (remain <= q) {
            elapsed += remain;
            cout << front.first << " " << elapsed << endl;
        } else {
            elapsed += q;
            front.second -= q;
            procs.push(front);
        }
    }

    return (0);
}