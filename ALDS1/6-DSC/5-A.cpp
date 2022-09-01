/* [ビット]全探索 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    rep(i, n) {
        cin >> A.at(i);
        // cout << i << ":" << A.at(i) << endl;
    }

    /* 全組合せの列挙 */
    set<int> all;
    for (int b = 0; b < (1 << n); b++) {
        int sum = 0;
        rep(i, n) {
            if ((b >> i) & 1) {
                sum += A[i];
            }
        }
        all.insert(sum);
    }

    int q, m;
    cin >> q;
    rep(i, q) {
        cin >> m;
        if (all.find(m) != all.end()) {  // 全組合せに含まれていない
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return (0);
}