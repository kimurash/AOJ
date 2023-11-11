// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 n;

    do{
        cin >> n;
        if(n == 0){
            break;
        }

        i16 w[n + 1];
        rep(i, 1, n){
            cin >> w[i];
        }

        // dp[i][j] = [i, j]で叩き出せるブロックの最大数
        i32 dp[n + 1][n + 1];
        rep(i, 1, n){
            rep(j, 1, n){
                dp[i][j] = 0;
            }
        }

        for(int len = 2; len <= n; len++){
            for(int l = 1; l + len - 1 <= n; l++){
                int r = l + len - 1;
                if(dp[l + 1][r - 1] == len - 2){
                    if(abs(w[l] - w[r]) <= 1){
                        dp[l][r] = max(dp[l][r], len);
                    } else{
                        dp[l][r] = max(dp[l][r], len - 2);
                    }
                }
                for(int k = l; k <= r - 1; k++){
                    dp[l][r] = max(
                        dp[l][r],
                        dp[l][k] + dp[k + 1][r]
                    );
                }
            }
        }

        cout << dp[1][n] << endl;
    } while(true);

    return(0);
}