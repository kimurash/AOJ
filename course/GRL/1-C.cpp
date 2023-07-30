// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAX_VERTEX 100
#define MAX_EDGE 9900
#define MAX_COST 20'000'000

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i64 dist[MAX_VERTEX][MAX_VERTEX];

int main(){
    cin.tie(nullptr);

    i32 V, E;
    cin >> V >> E;

    rep(i, 0, V - 1){
        rep(j, 0, V - 1){
            if(i == j){
                dist[i][j] = 0;
            } else{
                // 負の辺が存在するので初期値に余裕を持たせておく
                dist[i][j] = (2LL * MAX_COST) * MAX_EDGE;
            }
        }
    }

    i32 s[E], t[E], d[E];
    rep(i, 0, E - 1){
        cin >> s[i] >> t[i] >> d[i];
        dist[s[i]][t[i]] = d[i];
    }

    rep(k, 0, V - 1){
        rep(i, 0, V - 1){
            rep(j, 0, V - 1){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    rep(i, 0, V - 1){
        if(dist[i][i] < 0){
            cout << "NEGATIVE CYCLE" << endl;
            return(0);
        }
    }

    rep(i, 0, V - 1){
        rep(j, 0, V - 1){
            if(dist[i][j] >= (1LL * MAX_COST) * MAX_EDGE){
                cout << "INF";
            } else{
                cout << dist[i][j];
            }
            if(j != V - 1){
                cout << " ";
            }
        }
        cout << endl;
    }

    return(0);
}