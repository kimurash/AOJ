#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_SIDE 1400

using namespace std;

int16_t H, W;
bool tile[MAX_SIDE][MAX_SIDE];
int16_t T[MAX_SIDE][MAX_SIDE + 1];
// 上に向かって綺麗なタイルが何個連続しているか

// ヒストグラムに含まれる最大の長方形を求める
int64_t find_rec_in_hist(int row){
    int64_t height, pos;
    int64_t max_area = 0;
    stack<pair<int64_t, int64_t> > rects;

    rep(j, W + 1){
        if(rects.empty()){  // スタックが空
            rects.push(make_pair(T[row][j], j));
            // printf("push:(%d, %d)\n", T[row][j], j);
        } else{
            tie(height, pos) = rects.top();
            if(height < T[row][j]){   // トップの長方形より高い
                rects.push(make_pair(T[row][j], j));
                // printf("push:(%d, %d)\n", T[row][j], j);
            } else if(height > T[row][j]){  // トップの長方形より低い
                int64_t area;
                do{
                    // [HACK]: 最初の1回は冗長
                    tie(height, pos) = rects.top();
                    rects.pop();
                    // cout << "pop" << endl;

                    area = height * (j - pos);
                    max_area = max(max_area, area);
                } while(!rects.empty() && rects.top().first >= T[row][j]);

                rects.push(make_pair(T[row][j], pos));
                // printf("push:(%d, %d)\n", T[row][j], pos);
            }
        }
    }

    return(max_area);
}

int main(){
    cin >> H >> W;

    int is_dirty;
    // 入力と同時にテーブルを作成
    rep(i, H){
        rep(j, W){
            cin >> is_dirty;
            if(is_dirty == 1){
                tile[i][j] = true;
                T[i][j] = 0;
            } else{
                tile[i][j] = false;
                if(i == 0){
                    T[i][j] = 1;
                } else{
                    T[i][j] = T[i-1][j] + 1;
                }
            }
        }
        T[i][W] = 0;    // 番兵をセット
    }

    int64_t max_area = 0;
    rep(i, H){
        max_area = max(
            max_area, find_rec_in_hist(i)
        );
    }

    cout << max_area << endl;
}