/* 繰り返し自乗法 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define LAW 1000000007

using namespace std;

uint64_t recur_sqpow(uint64_t m, int n) {
    if (n == 0) {
        return (1);
    }
    if (n == 1) {
        return (m);
    }

    uint64_t ans = recur_sqpow((m * m) % LAW, n / 2);
    if ((n & 1) == 1) {
        ans = (ans * m) % LAW;
    }
    return (ans);
}

int main() {
    uint64_t m;
    int n;

    cin >> m >> n;
    cout << recur_sqpow(m, n) << endl;
    return (0);
}