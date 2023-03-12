/* バブルソートと選択ソートの比較 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

void show_all(vector<string> A, int N) {
    rep(i, N - 1) { cout << A[i] << " "; }
    cout << A[N - 1] << endl;
}

void bubble_sort(vector<string>& A, int N) {
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = N - 1; j >= 1; j--) {
            if (A[j - 1][1] > A[j][1]) {
                string temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = true;
            }
        }
    }

    return;
}

void selection_sort(vector<string>& A, int N) {
    rep(i, N) {
        int minj = i;  // 未整列部分で最小値を取る添え字
        rep2(j, i, N) {
            if (A[minj][1] > A[j][1]) {
                minj = j;
            }
        }

        if (minj != i) {
            string temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
        }
    }

    return;
}

// バブルソートと選択ソートの結果を比較
bool is_stable(vector<string> A, vector<string> B, int N) {
    rep(i, N) {
        if (A[i] != B[i]) {
            return (false);
        }
    }
    return (true);
}

int main() {
    int N;
    cin >> N;

    vector<string> Ab(N), As(N);
    rep(i, N) {
        cin >> Ab[i];
        As[i] = Ab[i];
    }

    bubble_sort(Ab, N);
    show_all(Ab, N);
    cout << "Stable" << endl;

    selection_sort(As, N);
    show_all(As, N);
    if (is_stable(Ab, As, N)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    return (0);
}