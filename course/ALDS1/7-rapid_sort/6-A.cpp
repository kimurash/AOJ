/* 分布数え上げソート */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

/**
 * @param n 入力Aの要素数
 * @param k 入力Aの最大値
*/
void counting_sort(uint16_t *A, uint16_t *B, int n, uint16_t k) {
    uint32_t C[k + 1] = {0};  // カウンタ配列

    // C[i]にiの出現数を記録
    rep(i, n) { C[A[i]]++; }

    // C[i]にi以下の出現数を記録
    rep2(i, 1, k + 1) { C[i] = C[i] + C[i - 1]; }

    for (int j = n - 1; j >= 0; j--) {
        B[--C[A[j]]] = A[j];
        // C[A[j]]--;
    }

    return;
}

void show_all(uint16_t *B, int n) {
    rep(i, n - 1) { cout << B[i] << " "; }
    cout << B[n - 1] << endl;
}

int main() {
    int n;
    cin >> n;

    uint16_t max = 0;
    uint16_t A[n] = {0}, B[n] = {0};
    rep(i, n) {
        cin >> A[i];
        if (max < A[i]) {
            max = A[i];
        }
    }

    counting_sort(A, B, n, max);
    show_all(B, n);
    return (0);
}