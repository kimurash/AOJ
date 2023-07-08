#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t N, W;
    cin >> N >> W;

    int16_t value[N+1], weight[N+1];
    rep(i, 1, N + 1){
        cin >> value[i] >> weight[i];
    }

    int32_t tab[N+1][W+1];
    tab[0][0] = 0;
    rep(j, 1, W + 1){
        tab[0][j] = -1;
    }

    rep(i, 1, N + 1){
        rep(j, 0, W + 1){
            tab[i][j] = tab[i-1][j];

            if(j >= weight[i]){
                tab[i][j] = max(
                    tab[i-1][j],
                    tab[i][j - weight[i]] + value[i]
                );
            }
        }
    }

    int32_t maxv = 0;
    rep(j, 0, W + 1){
        maxv = max(maxv, tab[N][j]);
    }

    cout << maxv << endl;
}