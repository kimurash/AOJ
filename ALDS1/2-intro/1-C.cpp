/* 素数判定 */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

bool is_prime(int32_t n) {
    if (n < 2) {
        return (false);
    } else if (n == 2) {
        return (true);
    } else {
        if ((n & 1) == 0) {  // 2以外の偶数
            return (false);
        } else {  // 2より大きい奇数
            // 奇数についてのみ調べればよい
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    return (false);
                }
            }
            return (true);
        }
    }
}

int main() {
    int n;
    cin >> n;

    uint16_t count = 0;
    uint32_t nums[n];
    rep(i, n) {
        cin >> nums[i];
        if (is_prime(nums[i])) {
            count++;
        }
    }
    cout << count << endl;
    return (0);
}