/* バブルソート */
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

    int count = 0;  // 入れ替えた回数
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = N - 1; j >= 1; j--) {
            if (A[j - 1] > A[j]) {  // 昇順になっていない
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;

                count++;
                flag = true;
            }
        }
    }

    show_all(A, N);
    cout << count << endl;
}