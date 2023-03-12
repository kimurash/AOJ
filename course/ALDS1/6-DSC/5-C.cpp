/* コッホ曲線 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define THETA (M_PI * 60.0 / 180.0)

using namespace std;

typedef struct point{
    double x, y;
} Point;

void koch(int d, const Point *p1, const Point *p2){
    // ベースケース
    if(d <= 0){ return; }

    // 再帰ステップ
    Point s, t, u;
    s.x = (2.0 * p1->x + p2->x) / 3.0;
    s.y = (2.0 * p1->y + p2->y) / 3.0;

    t.x = (p1->x + 2.0 * p2->x) / 3.0;
    t.y = (p1->y + 2.0 * p2->y) / 3.0;

    // 回転行列による計算を成分ごとに行う
    u.x = (t.x - s.x) * cos(THETA) - (t.y - s.y) * sin(THETA) + s.x;
    u.y = (t.x - s.x) * sin(THETA) + (t.y - s.y) * cos(THETA) + s.y;

    koch(d-1, p1, &s);
    cout << s.x << " " << s.y << endl;
    koch(d-1, &s, &u);
    cout << u.x << " " << u.y << endl;
    koch(d-1, &u, &t);
    cout << t.x << " " << t.y << endl;
    koch(d-1, &t, p2);
    
    return;
}

int main(){
    int n;
    cin >> n;

    Point p1{0.0, 0.0};
    Point p2{100.0, 0.0};

    cout << p1.x << " " << p1.y << endl;
    koch(n, &p1, &p2);
    cout << p2.x << " " << p2.y << endl;

    return(0);
}