#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MAX_H 30
#define MAX_W 30

using namespace std;

bool wall_vrt[MAX_H + 1][MAX_W];
bool wall_hrz[MAX_H][MAX_W + 1];
int32_t footprint[MAX_H][MAX_W];

bool explore_maze(int x, int y, int32_t steps);

int main(){
    int16_t w, h;

    do{
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }

        int16_t input;
        rep(i, 0, h + 1){
            // 縦方向の壁
            rep(j, 0, w){
                if(i == 0 || i == h){
                    wall_vrt[i][j] = 1;
                } else{
                    cin >> input;
                    wall_vrt[i][j] = input == 1;
                }
            }

            if(i == h){ continue; }

            // 横方向の壁
            rep(j, 0, w + 1){
                if(j == 0 || j == w){
                    wall_hrz[i][j] = 1;
                } else{
                    cin >> input;
                    wall_hrz[i][j] = input == 1;
                }
            }
        }

        fill(*footprint, *(footprint + h), INT32_MAX);
        bool reach = explore_maze(w - 1, h - 1, 1);
        if(reach){
            cout << footprint[0][0] << endl;
        } else{
            cout << 0 << endl;
        }
    } while(true);
}

// ゴールから幅優先探索する
bool explore_maze(int x, int y, int32_t steps){
    footprint[y][x] = steps;
    if(x == 0 && y == 0){
        return(true);
    }

    bool reach = false;
    if(!wall_vrt[y][x]){ // 上
        if(steps + 1 < footprint[y - 1][x]){
            reach = explore_maze(x, y - 1, steps + 1) || reach;
        }
    }

    if(!wall_vrt[y + 1][x]){ // 下
        if(steps + 1 < footprint[y + 1][x]){
            reach = explore_maze(x, y + 1, steps + 1) || reach;
        }
    }

    if(!wall_hrz[y][x + 1]){ // 右
        if(steps + 1 < footprint[y][x + 1]){
            reach = explore_maze(x + 1, y, steps + 1) || reach;
        }
    }

    if(!wall_hrz[y][x]){ // 左
        if(steps + 1 < footprint[y][x - 1]){
            reach = explore_maze(x - 1, y, steps + 1) || reach;
        }
    }

    return(reach);
}
