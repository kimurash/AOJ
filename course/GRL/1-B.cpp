// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXEDGE 2000
#define MAXCOST 10000

using namespace std;

int main() {
    int32_t V, E, r;
    cin >> V >> E >> r;

    int32_t s[E], t[E], d[E];
    rep(i, 0, E - 1) {
        cin >> s[i] >> t[i] >> d[i];
    }

    int32_t dist[V];
    rep(i, 0, V - 1) {
        // 負の辺が存在するので初期値に余裕を持たせておく
        dist[i] = 2 * MAXCOST * MAXEDGE;
    }
    dist[r] = 0;

    rep(i, 1, V){
        rep(j, 0, E - 1){
            if(dist[s[j]] < MAXCOST * MAXEDGE
                && dist[t[j]] > dist[s[j]] + d[j]){
                dist[t[j]] = dist[s[j]] + d[j];

                if(i == V){
                    // V回目のループで更新がある場合は負の閉路が存在する
                    cout << "NEGATIVE CYCLE" << endl;
                    return(0);
                }
            }
        }
    }

    rep(i, 0, V - 1){
        if(dist[i] >= MAXCOST * MAXEDGE){
            cout << "INF" << endl;
        } else{
            cout << dist[i] << endl;
        }
    }

    return (0);
}