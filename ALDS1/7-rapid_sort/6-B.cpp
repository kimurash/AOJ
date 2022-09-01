/* パーティション */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int partition(int32_t *A, int p, int r) {
    int32_t x = A[r];
    int i = p - 1;
    /*  [p, i]は枢軸以下
        (i, j]は枢軸より大きい
        (j, r]は不明    */
    rep2(j, p, r) {
        if (A[j] <= x) {
            i += 1;
            int32_t temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int32_t temp = A[++i];
    A[i] = A[r];
    A[r] = temp;

    return (i);
}

void show_all(int32_t *A, int pivot, int r) {
    rep(i, pivot) { cout << A[i] << " "; }
    cout << "[" << A[pivot] << "] ";
    rep2(i, pivot + 1, r) { cout << A[i] << " "; }
    cout << A[r] << endl;

    return;
}

int main() {
    int n;
    cin >> n;

    int32_t A[n] = {0};
    rep(i, n) { cin >> A[i]; }

    int pivot = partition(A, 0, n - 1);
    show_all(A, pivot, n - 1);
    return (0);
}