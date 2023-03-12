/* 最大正方形 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_SIDE 1400

using namespace std;

int16_t H, W;
bool tile[MAX_SIDE][MAX_SIDE];

int main(){
    cin >> H >> W;

    int is_dirty;   // int8_tだと0でもtrueになる
    rep(i, H){
        rep(j, W){
            cin >> is_dirty;
            if(is_dirty == 1){
                tile[i][j] = true;
            } else{
                tile[i][j] = false;
            }
        }
    }
    
    int32_t max_width = 0;
    int32_t max_size[H][W];
    /* max_size[i][j]
        (i, j)を右下隅とする正方形の辺長の最大値
    */
    rep(i, H){
        rep(j, W){
            if(tile[i][j]){ // is dirty
                max_size[i][j] = 0;
            } else{         // clean
                if(i == 0 || j == 0){
                    max_size[i][j] = 1;
                } else{
                    // min(左上,上,左)
                    max_size[i][j] = min(
                        max_size[i - 1][j - 1],
                        min(max_size[i-1][j],
                            max_size[i][j - 1]
                        )
                    ) + 1;
                }

                if(max_width < max_size[i][j]){
                    max_width = max_size[i][j];
                }
            }
        }
    }

    cout << max_width * max_width << endl;
}