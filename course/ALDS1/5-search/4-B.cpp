/* 2分探索 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    uint32_t n;
    cin >> n;
    uint32_t S[n] = {0};
    rep(i, n) { cin >> S[i]; }

    uint16_t q;
    cin >> q;
    uint32_t T[q] = {0};
    rep(i, q) { cin >> T[i]; }

    uint16_t count = 0;

    uint32_t low, high, middle;
    rep(i, q) {
        low = 0;
        high = n - 1;

        while (low <= high) {
            middle = (low + high) / 2;
            if (T[i] == S[middle]) {
                count++;
                break;
            } else if (T[i] < S[middle]) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }
    }

    cout << count << endl;
    return (0);
}