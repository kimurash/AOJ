#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MAX_ROW 50
#define MAX_COLUMN 50

using namespace std;

int16_t chart[MAX_ROW][MAX_COLUMN];
int16_t worksheet[MAX_ROW][MAX_COLUMN];

bool to_be_marked(int16_t x, int16_t y){
    if(x < 0 || MAX_COLUMN <= x || y < 0 || MAX_ROW <= y){
        return(false);
    }

    switch(chart[y][x]){
        case -1: // 海域外
        case 0:  // 海
            return(false);
        case 1: // 陸
            if(worksheet[y][x] == 0){
                // まだマークされていない
                return(true);
            } else{
                // 既にマークされている
                return(false);
            }
    }

    return(false);
}

void mark_adjacent(int16_t x, int16_t y, uint16_t id){
    if(!to_be_marked(x, y)){
        return;
    }

    worksheet[y][x] = id;

    mark_adjacent(x - 1, y - 1, id); // 左上
    mark_adjacent(x, y - 1, id);     // 上
    mark_adjacent(x + 1, y - 1, id); // 右上

    mark_adjacent(x - 1, y, id); // 左
    mark_adjacent(x + 1, y, id); // 右

    mark_adjacent(x - 1, y + 1, id); // 左下
    mark_adjacent(x, y + 1, id);     // 下
    mark_adjacent(x + 1, y + 1, id); // 右下
}

int main(){
    do{
        int16_t w, h;
        cin >> w >> h;

        if(w == 0 && h == 0){
            break;
        }

        rep(i, 0, h){
            rep(j, 0, w){
                cin >> chart[i][j];
                worksheet[i][j] = 0;
            }
            if(w < MAX_COLUMN){
                // 最右列を-1にする
                chart[i][w] = -1;
            }

            if(h < MAX_ROW){
                // 最下列を-1にする
                rep(j, 0, w){
                    chart[h][j] = -1;
                }

                if(w < MAX_COLUMN){
                    chart[h][w] = -1;
                }
            }
        }

        uint16_t count = 0;
        rep(i, 0, h){
            rep(j, 0, w){
                if(chart[i][j] == 1 && worksheet[i][j] == 0){
                    // まだマークされていない陸だった場合
                    mark_adjacent(j, i, ++count);
                }
            }
        }

        cout << count << endl;
    } while(true);
}
