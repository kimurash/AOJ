/* マージソート(配列) */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define MAX_ELEM 100010      // 作業用領域の大きさ
#define SENTINEL 1000000001  // 番兵

using namespace std;

int32_t L[MAX_ELEM], R[MAX_ELEM];

void show_all(const int32_t *A, int n) {
    rep(i, n) { cout << A[i] << " "; }
    cout << endl;
    return;
}

void merge_sort(int32_t *A, int low, int high, uint64_t *cnt) {
    // 要素が1つしかなければ即リターン
    if (low >= high) {
        return;
    }

    // 分割する境界を決定
    int middle = (low + high) / 2;

    // 前半をマージソート
    merge_sort(A, low, middle, cnt);

    // 後半をマージソート
    merge_sort(A, middle + 1, high, cnt);

    // cout << "sort(" << low << ", " << high << ")" << endl;
    // 前半を作業用配列にコピー
    int n1 = middle - low + 1;  // 前半の個数
    int n2 = high - middle;     // 後半の個数

    for (int i = 0; i < n1; i++) {
        L[i] = A[low + i];
    }
    L[n1] = SENTINEL;
    // show_all(L, n1);

    // 後半を作業用配列にコピー
    for (int i = 0; i < n2; i++) {
        R[i] = A[(middle + 1) + i];
    }
    R[n2] = SENTINEL;
    // show_all(R, n2);

    // 前半と後半をマージ
    int i = 0, j = 0;
    for (int k = low; k <= high; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
            (*cnt) += n1 - i;
            // cout << *cnt << endl;
        }
    }

    return;
}

int main() {
    int n;
    cin >> n;

    int32_t A[n] = {0};
    rep(i, n) { cin >> A[i]; }

    uint64_t count = 0;  // 反転数
    merge_sort(A, 0, n - 1, &count);

    // show_all(A, n);
    cout << count << endl;
    return (0);
}