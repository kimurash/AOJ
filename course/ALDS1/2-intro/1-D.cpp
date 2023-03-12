#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int n;
    cin >> n;

    int32_t maxv = -1000000000; // 十分小さい値で初期化
    int32_t minv, R;

    cin >> minv;
    rep(i, n - 1){
        // cout << "maxv:" << maxv << endl;
        // cout << "minv:" << minv << endl;

        cin >> R;
        maxv = max(maxv, R - minv);
        minv = min(minv, R); // 現時点までの最小値を保持
    }

    cout << maxv << endl;
    return(0);
}