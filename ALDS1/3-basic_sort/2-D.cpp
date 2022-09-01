/* シェルソート */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int32_t cnt = 0;

void show_all(vector<int32_t> A, int32_t N) {
    rep(i, N - 1) { cout << A[i] << " "; }
    cout << A[N - 1] << endl;

    return;
}

// 間隔gを指定した挿入ソート
void insertion_sort(vector<int32_t>& A, int32_t N, int32_t g) {
    rep(i, N) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }

    return;
}

void shell_sort(vector<int32_t>& A, int32_t N) {
    cnt = 0;

    // 間隔を要素とする配列で生成
    int32_t g = 1;
    vector<int32_t> G;
    while (g <= N) {
        G.push_back(g);
        g = 3 * g + 1;
    }
    cout << G.size() << endl;

    for (int i = G.size() - 1; i >= 0; i--) {  // 逆順に間隔を指定
        cout << G[i];
        if (i) {
            cout << " ";
        }
        insertion_sort(A, N, G[i]);
    }
    cout << endl;

    return;
}

int main() {
    int32_t N;
    cin >> N;

    vector<int32_t> A(N);
    rep(i, N) { cin >> A[i]; }

    shell_sort(A, N);
    cout << cnt << endl;
    rep(i, N) { cout << A[i] << endl; }

    return (0);
}