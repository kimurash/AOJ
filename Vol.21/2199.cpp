// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

#define STEP 255
#define INF 1e9

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return(true);
    }
    return(false);
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return(true);
    }
    return(false);
}

int main(){
    cin.tie(nullptr);

    i16 M;
    i32 N;

    do{
        cin >> N >> M;
        if(N == 0 && M == 0){
            break;
        }

        i16 codebook[M + 1];
        i16 pulse[N + 1];

        rep(i, 1, M){
            cin >> codebook[i];
        }

        rep(i, 1, N){
            cin >> pulse[i];
        }

        // dp[i][j]: i番目の復号化後の信号がjであるときの最小誤差
        i32 dp[N + 1][STEP + 1];
        rep(i, 0, N){
            rep(j, 0, STEP){
                dp[i][j] = INF;
            }
        }
        dp[0][128] = 0;

        // 配る遷移形式
        rep(i, 0, N - 1){
            rep(j, 0, STEP){ // i番目の復号化後の信号
                if(dp[i][j] == INF){
                    continue;
                }

                rep(k, 1, M){
                    i32 next = j + codebook[k];
                    next = max(next, 0);
                    next = min(next, STEP);

                    i32 err = pulse[i + 1] - next;
                    dp[i + 1][next] = min(
                        dp[i + 1][next],
                        dp[i][j] + err * err
                    );
                }
            }
        }

        i32 ans = INF;
        rep(j, 0, STEP){
            chmin(ans, dp[N][j]);
        }
        cout << ans << endl;
    } while(true);

    return(0);
}