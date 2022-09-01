/* 挿入ソート */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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

    rep(i, N) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        show_all(A, N);
    }

    return (0);
}
