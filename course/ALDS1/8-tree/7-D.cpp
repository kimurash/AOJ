/* 木の復元 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// #define MAX_NODE 100

using namespace std;

int root_id = 0;
vector<uint16_t> pre, in, post;
// [XXX]: uint8_tだと1桁ずつしか入力されない

// [left, right)の部分木を復元する
void reconstruct(int left, int right) {
    // cout << "reconst(" << left << ", " << right << ")" << endl;
    if (left >= right) {
        return;
    }

    int root = pre[root_id++];  // preorderでの次の節点
    vector<uint16_t>::iterator loc = find(in.begin(), in.end(), root);
    int dist = distance(in.begin(), loc);

    reconstruct(left, dist);
    reconstruct(dist + 1, right);
    post.push_back(root);  // postorderだから最後に追加

    return;
}

int main() {
    int n;
    cin >> n;

    uint16_t id;
    rep(i, n) {
        cin >> id;
        pre.push_back(id);
    }

    rep(i, n) {
        cin >> id;
        in.push_back(id);
    }

    reconstruct(0, n);

    cout << post.at(0);
    rep2(i, 1, n) { cout << " " << post.at(i); }
    cout << endl;

    return (0);
}