/* フィボナッチ数列 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

uint64_t fib(int n) {
    uint64_t n0 = 1, n1 = 1;

    if (n == 0) {
        return (n0);
    } else if (n == 1) {
        return (n1);
    } else {
        for (uint32_t i = 1; i < n; i++) {
            n0 ^= n1;
            n1 ^= n0;
            n0 ^= n1;
            n1 += n0;
        }
        return (n1);
    }
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return (0);
}
