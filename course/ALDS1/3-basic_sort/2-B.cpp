/* 選択ソート */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

void show_all(vector<int> A, int N) {
    rep(i, N - 1) { cout << A[i] << " "; }
    cout << A[N - 1] << endl;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }

    int count = 0;
    rep(i, N) {
        int minj = i;  // 未整列部分で最小値を取る添字
        rep2(j, i, N) {
            if (A[minj] > A[j]) {
                minj = j;
            }
        }

        if (minj != i) {  // 左端が最小でない
            int temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            count++;
        }
    }

    show_all(A, N);
    cout << count << endl;

    return (0);
}