/* 最大公約数 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t x, y;
    cin >> x >> y;

    if(x < y){
        x ^= y;
        y ^= x;
        x ^= y;
    }
    // printf("x:%d\ty:%d\n", x, y);

    while(y > 0){
        int32_t r = x % y;
        x = y;
        y = r;
    }

    cout << x << endl;
    return(0);
}