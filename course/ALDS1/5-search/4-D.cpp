/* 最適解の計算 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAX_ITEM 100000
#define MAX_WEIGHT 10000

using namespace std;

uint32_t n, k;
uint32_t w[MAX_ITEM] = {0};

// 最大積載量Pのトラックk台で何個の荷物を詰めるか
uint32_t load_item_amap(uint32_t P) {
    uint32_t i = 0;  // i番目の荷物
    rep(j, k) {      // j番目のトラック
        uint64_t p = 0;
        while (p + w[i] <= P) {
            p += w[i];
            i++;
            if (i >= n) {
                return (n);
            }
        }
    }
    return (i);
}

// 最大積載量Pの最小値を二部探索
uint32_t search() {
    uint32_t low, high, middle;
    low = 0;
    high = MAX_WEIGHT * MAX_ITEM;

    while (low + 1 < high) {
        middle = (high + low) / 2;
        uint32_t i = load_item_amap(middle);
        if (i >= n) {
            high = middle;
        } else {
            low = middle;
        }
    }

    return (high);
}

int main() {
    cin >> n >> k;
    rep(i, n) { cin >> w[i]; }
    cout << search() << endl;

    return (0);
}