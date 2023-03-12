/* 連鎖行列積 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG

using namespace std;

int main() {
    int n;  // 行列の数
    cin >> n;

    // (n+1)x(n+1)としているのは添字が0の行/列は使用しないため
    int dim[n + 1], cost[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> dim[i - 1] >> dim[i];
    }

    for (int i = 1; i <= n; i++) {
        // 行列積を計算しない場合はコストは0
        cost[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {  // l: 対象とする行列の数
        /* [i, j]の範囲で最小コストを求める */
        // 末尾も含めてl戻った所がiの限界 => n - (l - 1)
        for (int i = 1; i <= n - l + 1; i++) {
            // iも含めてl進んだ所がjの位置
            int j = i + (l - 1);
            /* ((M_i, ..., M_k)(M_k+1, ..., M_j))の最小コストを求める */
            cost[i][j] = INT32_MAX;
            for (int k = i; k <= j - 1; k++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k + 1][j] +
                                                 dim[i - 1] * dim[k] * dim[j]);
            }
        }
    }

    cout << cost[1][n] << endl;
    return (0);
}