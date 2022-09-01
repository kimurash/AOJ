/* LIS: Longest Increasing Subsequence */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int main() {
    int n;
    cin >> n;

    int32_t numseq[n];
    rep(i, n) { cin >> numseq[i]; }

    int32_t LIS_last[n] = {0};
    // list_last[i] = (長さが(i+1)の最長増加部分列の最後の要素)の最小値

    int length = 1;  // 現時点の最長増加部分列の長さ
    LIS_last[0] = numseq[0];
    rep2(i, 1, n) {
        if (LIS_last[length - 1] < numseq[i]) {
        // 現在のLISの最後の要素よりも大きい
            LIS_last[length++] = numseq[i];
        } else {
        // LISを長くすることはできないが,
        // 長さがlegnth以下のLISの最後の要素を更新できる

            // LIS_last[0, legnth-1]でnumseq[i]以上となる最初の要素を更新
            // LIS_last[length-1] >= numseq[i]より必ず存在する
            *lower_bound(LIS_last, LIS_last + length, numseq[i]) = numseq[i];
        }
    }

    cout << length << endl;
    return (0);
}
