#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int64_t N;
    cin >> N;

    int64_t hist[N + 1];
    rep(i, N){ cin >> hist[i]; }
    hist[N] = 0;    // 番兵をセット

    int64_t height, pos;
    int64_t max_area = 0;
    stack<pair<int64_t, int64_t> > rects;
    rep(i, N + 1){
        if(rects.empty()){  // スタックが空
            rects.push(make_pair(hist[i], i));
            // printf("push:(%d, %d)\n", hist[i], i);
        } else{
            tie(height, pos) = rects.top();
            if(height < hist[i]){   // トップの長方形より高い
                rects.push(make_pair(hist[i], i));
                // printf("push:(%d, %d)\n", hist[i], i);
            } else if(height > hist[i]){  // トップの長方形より低い
                int64_t area;
                do{
                    // [HACK]: 最初の1回は冗長
                    tie(height, pos) = rects.top();
                    rects.pop();
                    // cout << "pop" << endl;

                    area = height * (i - pos);
                    max_area = max(max_area, area);
                } while(!rects.empty() && rects.top().first >= hist[i]);

                rects.push(make_pair(hist[i], pos));
                // printf("push:(%d, %d)\n", hist[i], pos);
            }
        }
    }

    cout << max_area << endl;
}